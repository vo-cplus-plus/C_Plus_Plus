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
        // поиск минимума и максимума
        int min = data[0], max = data[0];
        for (int i=1; i<n; i++){ 
            if (data[i] > max) max = data[i];
            if (data[i] < min) min = data[i];
        }
        if (max - min < 2){
            std:: cout << "Невозможно построить массив\n";
            continue;
        }       
        // создаем вспомогательный массив
        int *temp = new int[max-min-1];
        int index = 0;
        // перебор значений от min + 1 до max (не включая)
        for(int value = min + 1; value < max; value++){
            // проверяем, есть ли такое значение в массиве
            int k=0;
            for(; k < n; k++){
                if (data[k] == value) break;
            }
            if (k == n){
                temp[index++] = value;
            } 
        }
        if (index == 0){
            std:: cout << "Невозможно построить массив\n";
            continue;
        } 
        std:: cout << "Значения между min("<<min<<") и max ("<<max<<"):\n";
        for(int i=0; i<index; i++){
            std::cout << temp[i] << " ";
        }
        std::cout << std::endl;
        delete [] data;
    }
}


