// Дан массив целых чисел. 
// Из этого массива исключить все отрицательные числа
// (при этом предусмотреть, что каждое неотрицательное число сдвигается один раз).
// !!! Новый массив заводить нельзя !!!


#include <fstream>
#include <iostream>
int main(){
    std::ifstream input("data 05.txt"); //файл с данными
    int N; // количество массивов
    input >> N; // читаем из файла
    for(int test = 1; test <= N; test++){
        std::cout << "Тест № " << test << std::endl; 
        int n; // количество элементов в массиве
        input >> n; // читаем из файла
        int *data = new int[n]; // создаем массив
        for (int i=0; i<n; i++){ // считываем данные 
            input >> data[i];
        }
        // Решение задачи
        // ...
        
        delete [] data;
    }
}


