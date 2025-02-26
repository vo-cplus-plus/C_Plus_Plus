// Дан массив вещественных чисел. Исключить первую подпоследовательность
//  (два или более расположенных подряд) отрицательных элементов.

#include <fstream>
#include <iostream>
int main(){
    std::ifstream input("data 04.txt"); //файл с данными
    int N; // количество массивов
    input >> N; // читаем из файла
    for(int test = 1; test <= N; test++){
        std::cout << "Тест № " << test << std::endl; 
        int n; // количество элементов в массиве
        input >> n; // читаем из файла
        double *data = new double[n]; // создаем массив
        for (int i=0; i<n; i++){ // считываем данные 
            input >> data[i];
        }
        // Решение задачи
        // ...
        
        delete [] data;
    }
}


