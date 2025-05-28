#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Интерфейс Image
class Image {
public:
    virtual ~Image() = default;
    virtual void display() = 0;
};

// Реальный объект (загружает изображение сразу)
class RealImage : public Image {
private:
    string filename;
    void loadFromDisk() {
        cout << "Загрузка изображения: " << filename << " (считывание, обработка, запись... )" << endl;
    }
public:
    RealImage(const string& filename) : filename(filename) {
        loadFromDisk();
    }
    void display() override {
        cout << "Демонстрация изображения: " << filename << endl;
    }
};

// Прокси (ленивая загрузка)
class ProxyImage : public Image {
private:
    unique_ptr<RealImage> realImage;
    string filename;
    void log(string message){
        cout << "Log: " << message << endl;
    }
public:
    ProxyImage(const string& filename) : filename(filename) {}
    void display() override {
        if (!realImage) {
            realImage = make_unique<RealImage>(filename);
            log("Изображение создано");
        }
        realImage->display();
        log("Демострация изображения");
    }   
};

// Клиентский код
int main() {
    ProxyImage imageProxy("photo.jpg");

    // Изображение не загружается до вызова display()
    cout << "Прокси (заместитель создан). Изображение не загружено." << endl;

    // Первый вызов display() — загрузка и отображение
    imageProxy.display();

    // Второй вызов — изображение уже загружено
    imageProxy.display();

}