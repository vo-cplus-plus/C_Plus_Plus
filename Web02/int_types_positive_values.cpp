#include <iostream> // подключение библиотеки ввода / вывода
#include <fstream> // подключение библиотеки для работы с файлами

int main(){    
    // знаковые целые числа
    char var_char = 120;            // 1 байт
    short var_short = 120;          // 2 байта
    int var_int = 120;              // 4 байта    
    long long var_long = 120;       // 8 байтов
        
    // определяем размер памяти для каждого типа данных
    std::cout  << sizeof(int) << " " << sizeof(short) << " "
          << sizeof(long) << " " << sizeof(long long) << " "
          << sizeof(char) << std::endl;
    
    // создаем файл, который является образом оперативной памяти во внешней памяти
    std::ofstream output("memory.dat");
    // записываем в файл числа, так как они хранятся в памяти
    output.write(reinterpret_cast<const char *>(&var_char), sizeof(char));
    output.write(reinterpret_cast<const char *>(&var_short), sizeof(short));
    output.write(reinterpret_cast<const char *>(&var_int), sizeof(int));
    output.write(reinterpret_cast<const char *>(&var_long), sizeof(long long));    
}
