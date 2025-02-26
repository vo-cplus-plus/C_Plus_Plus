#include <iostream>
int main(){   // Можно определять массив, не указывая количество элементов, через список инициализации
  int numbers[]{1,2,3,4,5};
  //Тогда количество элементов можно определить 
  int size = sizeof(numbers) / sizeof(int);
  for(int i=0; i< size; i++){    
    // Выводим каждый элемент на экран
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

    // Для статических элементов можно использовать цикл for в стиле for-each
    // Предназначен специально для работы с последовательностями значений
  for(auto x:numbers){
    std::cout << x << " ";
  }
  std::cout << std::endl;
}
