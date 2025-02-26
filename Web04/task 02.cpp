// Дан массив значений ежедневного измерения температуры воздуха в марте. Определите
// сколько дней температура была ниже максимальной не более чем на 3°С 


#include <fstream>
#include <iostream>
int main(){
    std::ifstream input("data 02.txt"); //файл с данными
    int N; // количество массивов
    input >> N; // читаем из файла
    for(int test = 1; test <= N; test++){
        std::cout << "Тест № " << test << std::endl; 
        int n; // количество элементов в массиве
        input >> n; // читаем из файла
        double *T = new double[n]; // создаем массив
        for (int i=0; i<n; i++){ // считываем данные 
            input >> T[i];
        }
        // обработка массива
        // ...
        delete [] T;
    }
}


