// Дан массив значений ежедневного измерения температуры воздуха в марте. Определите
// день, когда температура была ближе всего к средней


#include <fstream>
#include <iostream>
int main(){
    std::ifstream input("data 01.txt"); //файл с данными
    int N; // количество массивов
    input >> N; // читаем из файла
    for(int test = 1; test <= N; test++){
        std::cout << "Тест № " << test << std::endl; 
        int n; // количество элементов в массиве
        input >> n; // читаем из файла
        double *T = new  double[n]; // создаем массив
        for (int i=0; i<n; i++){ // считываем данные 
            input >> T[i];
        }
        // поиск среднего значения
        double mean = 0.0;
        for (int i=0; i<n; i++){ // считываем данные 
            mean += T[i];
        }
        mean /= n;
        
        // определяем день, когда температура была ближе всего к средней
        int day = 0;
        double min = std::abs(T[0] - mean);
        for (int i=1; i<n; i++){ // считываем данные 
            if (std::abs(T[i] - mean) < min){
                min = std::abs(T[i] - mean);
                day = i;
            }
        }
        
        // вывод на экран результата
        std::cout << "День когда температура ближе всего к средней (" << mean << ") это " << day + 1 << " марта\n";
        delete [] T;
    }
}


