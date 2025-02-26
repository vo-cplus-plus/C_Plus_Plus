#include <iostream>
int main(){
   // Нельзя определять массив, не указывая количество элементов
  int size = 5;
  int * numbers = new int [size]{1,2,3,4,5};
  //int * numbers_err = new int []{1,2,3,4,5};        // Ошибка
  
  for(int i=0; i< size; i++){    
    // Выводим каждый элемент на экран
    std::cout << numbers[i] << " ";
  }

  std::cout << std::endl;
  // Нельзя использовать цикл for в стиле for each
  for(auto x:numbers){                          // Ошибка
    std::cout << x << " ";
  }
  std::cout << std::endl;
}
