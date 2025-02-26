#include <fstream>
#include <iostream>
int main(){
    std::ifstream input("data.txt"); //файл с данными
    int N; // количество массивов
    input >> N; // читаем из файла
    for(int test = 1; test <= N; test++){
        std::cout << "Тест № " << test << std::endl; 
        int n; // количество элементов в массиве
        input >> n; // читаем из файла
        int *array = new int[n]; // создаем массив
        for (int i=0; i<n; i++){ // считываем данные 
            input >> array[i];
        }
        // обработка массива
        // ...
        delete [] array;
    }
}
