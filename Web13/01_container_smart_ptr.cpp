#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

// Общий ресурс
class SharedResource: public enable_shared_from_this<SharedResource> {
public:
    string data;
    SharedResource(string d) : data(move(d)) {
        cout << "[Общий ресурс] " << data << " создан\n";
    }
    ~SharedResource() {
        cout << "[Общий ресурс] " << data << " удален\n";
    }
    void getStatus() const{
         cout << "Ресурс используется: " << shared_from_this().use_count() << " объектами\n";
    }
};

// Контейнер
class Container; // Предварительное объявление

// Элемент контейнера
class Element {
    string name;
    shared_ptr<SharedResource> resource;  // разделенный указатель на общий ресурс
    weak_ptr<Container> container;           // слабый указатель на родителя
    
public:
    Element(string n, 
            shared_ptr<SharedResource> res)
        : name(move(n)),
          resource(move(res)) 
    {
        cout << "[Элемент] " << name << " создан\n";
    }

    void setContainer(weak_ptr<Container> c){
        this->container = c;
    }
    void resetContainer(){
        this->container.reset();
    }
    
    void doWork() const { // выполнение задачи
        // Проверяем, существует ли родитель через weak_ptr
        if (container.lock()) {
            cout << "[Элемент] " << name 
                      << " работает с: " << resource->data
                      << " (через контейнер)\n";
        } else {
            cout << "[Элемент] " << name 
                      << " работает с: " << resource->data
                      << " (контейнер удален)\n";
        }
        resource->getStatus();
    }
    
    const string& getName() const { return name; }
    
    ~Element() {
        cout << "[Элемент] " << name << " удален\n";
    }
};

// Контейнер (владеет и управляет элементами)
class Container : public enable_shared_from_this<Container> {
    string name;
    vector<unique_ptr<Element>> elements;  // массив уникальных указателей = 
                                           // = контейнер единственный владелец своих элементов
    
public:
    explicit Container(string n) 
        : name(move(n)) 
    {
        cout << "\n[Контейнер] " << name << " создан\n";
    }    
    
    void addElement(unique_ptr<Element> elem) {
        // Получаем shared_ptr на текущий Container
        std::shared_ptr<Container> self = shared_from_this();
        elem->setContainer(self);
        elements.push_back(move(elem));
        cout << "[Контейнер] " << name << " добавил элемент " << elements.back()->getName() << "\n";
    }
    
    void processAll() const {
        cout << "\n[Контейнер] " << name << " обрабатывает элементы\n";
        for (const auto& elem : elements) {
            elem->doWork();
        }
    }
    
    unique_ptr<Element> removeFirst() {
        unique_ptr<Element> res;
        if (!elements.empty()){      
            const string& elemName = elements.front()->getName();      
            res = move(elements.front());
            res->resetContainer();
            elements.erase(elements.begin());
            cout << "\n[Контейнер] " << name << " удалил элемент " << elemName << "\n";
           
        }
        return res;
    }
    
    ~Container() {
        cout << "\n[Контейнер] " << name << " удален\n";
    }
};

int main() {    
    auto resource = make_shared<SharedResource>("(Общие данные)");
    unique_ptr<Element> elem;    
    {
        auto container = make_shared<Container>("{Хранилище}");        
       
        container->addElement(make_unique<Element>("E1", resource));
        container->addElement(make_unique<Element>("E2", resource));
        container->addElement(make_unique<Element>("E3", resource));
        
        container->processAll();
                
        elem = container->removeFirst();
        elem->doWork();
        container->processAll();        
    }
    
    cout << "\n!!! После удаления контейнера !!!\n";
    elem->doWork();
    elem.reset();
    // Элементы уничтожены, но ресурс ещё жив (есть shared_ptr в main)
    resource->getStatus();    
    

    
}