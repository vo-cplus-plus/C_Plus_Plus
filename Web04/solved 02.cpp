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
        // находим максимальную температуру
        double max = T[0];
        for (int i=1; i<n; i++){ // считываем данные 
            if(T[i] > max) max = T[i];
        }

        // находим, сколько дней температура была ниже максимальной не более чем на 1°С
        int count = 0;
        for (int i=0; i<n; i++){ // считываем данные 
            if(T[i] > max - 3) count++;
        }

        // выводим результат
        
        std::cout << "Температура была ниже максимальной (" <<max<<") не более чем на 3°С " << count;
        if ((count > 10 && count < 21) || count % 10 > 4){
            std::cout << " дней\n";
        }
        else switch(count % 10){
            case '0': std::cout << " дней\n"; break;
            case '1': std::cout << " день\n"; break;
            default: std::cout << " дня\n";
        } 
        delete [] T;
    }
}


