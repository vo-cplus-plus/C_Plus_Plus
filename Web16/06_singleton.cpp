#include <memory>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Singleton {
private:
    // Приватный конструктор
    Singleton()=default;    
    // Удаление конструктора копирования
    Singleton(const Singleton&) = delete;
    // Удаление оператора копирования
    Singleton& operator=(const Singleton&) = delete;

    // Умный указатель для управления экземпляром
    static unique_ptr<Singleton> instance; 
    vector<string> messages;
public:
    // Метод доступа к экземпляру
    static Singleton& getInstance() {
        if (!instance)        
            instance.reset(new Singleton());        
        return *instance;
    } 
    // Пример метода класса (логирование сообщения)
    void log(const string& message) {
        messages.push_back(message);
    }
    void print(){
        for(const auto &message:messages) cout << message<< endl;
    }
    ~Singleton(){};
};

// Инициализация статических членов
unique_ptr<Singleton> Singleton::instance = nullptr;

int main(){
    {
    Singleton &s = Singleton::getInstance();
    s.log(string("Начало работы..."));
    s.log(string("Продолжение..."));
    }
    for(int i=0; i<5; i++){
        Singleton &s = Singleton::getInstance();
        s.log(string("Итерация..."));
    }
    Singleton &s = Singleton::getInstance();
    s.print();
}