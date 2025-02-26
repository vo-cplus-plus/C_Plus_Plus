#include <iostream>
int main(){
  // Массив из 5 нулей
  int *zeros = new int [5]{0,0,0,0,0};
  // Массив = точка в трёхмерном пространстве
  delete []zeros;
  double *point = new double[3]{1.0, 2.0, -1.5};
  delete []point;
  // Определяем переменную n и запрашиваем её значение
  int n; std:: cin >> n;
  // Массив из N элементов
  double *A = new double [n];
  // Заполняем массив значениями
  for(int i=0; i< n; i++){
    A[i] = (i + 1) / 10.0; // Целое / вещественное => вещественное
    // Выводим каждый элемент на экран
    std::cout << A[i] << " ";
  }
   for(double *p = A; p < A + n; p++){
    *p = (p - A + 1) / 5.0; // Целое / вещественное => вещественное
    // Выводим каждый элемент на экран
    std::cout << *p << " ";
  }
  std::cout << std::endl;
  delete[]A; 
}
