#include <iostream>
#include <cstdlib>

double randomDouble();
int randomInt(int a, int b);

int main(){    
    int N = 3; // количество массивов    
    for(int test = 1; test <= N; test++){
        std::cout << "Тест № " << test << std::endl; 
        int n = randomInt(5, 10); // количество элементов в 
                                  // массиве        
        int *array = new int[n]; // создаем массив
        for (int i=0; i<n; i++){ // генерируем данные 
            array[i] = randomInt(-10, 10);
        }
        // обработка массива
        // ...
        delete [] array;
    }
}
