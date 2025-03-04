// Даны целые числа а1...аn. Пусть m и М – наибольшее и наименьшее из них.
// Сформировать массив из целых чисел от m до М, не входящих в исходную последовательность а1...аn.
// Числа в новом массиве расположить в порядке возрастания.



#include <fstream>
#include <iostream>
int main(){
    std::ifstream input("data 03.txt"); //файл с данными
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
        // сортируем массив методом вставки
        for(int i=1; i < n; i++)
        	for(int j=i; j>0 && data[j-1] > data[j]; j--){
                int x = data[j]; data[j] = data[j-1]; data[j-1] = x;
            } 
        if (data[n-1] - data[0] < 2){
            std:: cout << "Невозможно построить массив!\n";
            continue;
        } 
        // создаем вспомогательный массив
        int *temp = new int[data[n-1] - data[0] - 1];
        int index = 0;
        // перебираем элементы по парам
        for (int i=1; i<n; i++){ 
            // значения между ними включаем в новый массив
            for(int k = data[i-1] + 1; k < data[i]; k++){
                temp[index++] = k;
            }            
        }                     
        if (index == 0){
            std:: cout << "Невозможно построить массив!\n";
            continue;
        } 
        std:: cout << "Значения между min("<<data[0]<<") и max ("<<data[n-1]<<"):\n";
        for(int i=0; i<index; i++){
            std::cout << temp[i] << " ";
        }
        std::cout << std::endl;
        delete [] data;
    }
}



/// 6 3 7 1 1 3 7
//  1 1 3 3 6 7

// RES: 2 4 5


