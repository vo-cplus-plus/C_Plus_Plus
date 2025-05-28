#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

// Интерфейс наблюдателя
class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(float stormProbability) = 0;
};

// Наблюдаемый объект (Subject)
class WeatherStation {
private:
    vector<IObserver*> observers;
    float stormProbability;

public:
    void addObserver(IObserver* observer) {
        observers.push_back(observer);
    }

    void removeObserver(IObserver* observer) {
        auto it = remove(observers.begin(), observers.end(), observer);
        observers.erase(it, observers.end());
    }

    void setState(float stormProbability) {
        this->stormProbability = stormProbability;
        if (stormProbability > 50) notify();
    }

    void notify() {
        for (auto observer : observers) {
            observer->update(stormProbability);
        }
    }
};

// Конкретный наблюдатель
class Observer : public IObserver {
public:
    void update(float stormProbability) override {
        if (stormProbability > 90) cout << "Надо прятаться!!!" << endl;
        else if (stormProbability > 75) cout << "Надо поискать укрытие!" << endl;
        else cout << "Надо быть внимательным!" << endl;
    }
};

// Конкретный наблюдатель
class BraveObserver : public IObserver {
public:
    void update(float temperature) override {
        cout << "Надо быть внимательным!" << endl;
    }
};

// Клиентский код
int main() {
    WeatherStation station;
    Observer observer;
    BraveObserver brave;

    // Подписка наблюдателей
    station.addObserver(&observer);
    station.addObserver(&brave);

    // Прогнозирование
    station.setState(40.0); // не будет рассылки
    station.setState(95.0); // рассылка
    station.setState(80.0); // рассылка
    station.setState(70.0); // рассылка
    station.setState(30.0); // не будет рассылки

    // Отписка 
    station.removeObserver(&brave);
    station.setState(85.0); // brave не получит уведомление
}