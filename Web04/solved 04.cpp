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
        // находим первое отрицательное число
        int first, second = -1;
        do{
            first = second + 1;
            for(; first < n && data[first] >= 0; first++);           
            if (first < n){
                second = first + 1;
                for(; second < n && data[second] < 0; second++);     
            }                       
        }while (first < n && second - first < 2);
        if(first == n){
            std::cout << "Нет последовательности отрицательных чисел\n";
            continue;
        }
        int res_len = n - second + first;
        if(res_len == 0){
            std::cout << "Результирующий массив пуст\n";
            continue;
        }
        double * res = new double[res_len];
        for(int i=0; i<first; i++) res[i] = data[i];
        for(int i=second, j = first; i<n; i++, j++){res[j] = data[i];}
        std:: cout << "Массив после удаления последовательности отрицательных чисел:\n";
        for(int i=0; i<res_len; i++){
            std::cout << res[i] << " ";
        }
        std::cout << std::endl;
        delete [] data;
    }
}


