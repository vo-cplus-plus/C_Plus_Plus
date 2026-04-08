#include <iostream>
#include <algorithm>
#include <cstring>

class Matrix {
private:
    int* data;
    size_t rows;
    size_t cols;
    static size_t numberOfAllocations;

public:
    // Конструктор по умолчанию
    Matrix() : data(___1___), rows(0), cols(0) {}
    
    // Параметризованный конструктор
    Matrix(size_t r, size_t c, int initValue = 0) 
        : rows(r), cols(c) {        
        data = ___2___;
        std::fill(data, data + rows * cols, initValue);
        ___3___;
    }
    
    // Конструктор копирования
    Matrix(const Matrix& other) 
        : rows(other.rows), cols(other.cols) {        
        data = ___4___;
        std::copy(other.data, other.data + rows * cols, data);
        ___5___;
    }
    
    // Конструктор перемещения
    Matrix(Matrix&& other) ___6___ 
        : data(other.data), rows(other.rows), cols(other.cols) {        
        other.data = ___7___;
        other.rows = 0;
        other.cols = 0;
    }
    
    // Деструктор
    ~Matrix() {        
        if (___8___) {
            delete[] data;
            ___9___;
        }
    }
    
    // Копирующее присваивание
    // Можно ли реализовать иначе?
    Matrix& operator=(const Matrix& other) {        
        if (___10___) {
            return *this;
        }
        
        // Освобождаем старые ресурсы
        if (data) {
            delete[] data;
            numberOfAllocations--;
        }
        
        rows = other.rows;
        cols = other.cols;
        data = __11__;
        std::copy(other.data, other.data + rows * cols, data);
        numberOfAllocations++;
        
        return *this;
    }
    
    // Перемещающее присваивание
    // Можно ли реализовать иначе?
    Matrix& operator=(Matrix&& other) ___12___ {        
        if (___13___) {
            return *this;
        }
        
        // Освобождаем текущие ресурсы
        if (data) {
            delete[] data;
            numberOfAllocations--;
        }
        
        // Перемещаем ресурсы
        data = __14__;
        rows = other.rows;
        cols = other.cols;
        
        // Оставляем other в валидном состоянии
        other.data = ___15___;
        other.rows = 0;
        other.cols = 0;
        
        return *this;
    }
    
    // Метод доступа
    int& at(size_t row, size_t col) {
        return data[___16___];
    }
    
    // В чем отличие от предыдущего метода?
    //  Почему важно реализовать оба?
    const int& at(size_t row, size_t col) const {
        
        return data[___16___];
    }
    
    // Метод для получения размера
    size_t getSize() const { return rows * cols; }
    
    // метод для проверки "утечек" памяти 
    ___17___ size_t getAllocationCount() { return numberOfAllocations; }
    
    // Метод для обмена содержимым
    void swap(Matrix& other) noexcept {
        std::swap(data, other.data);
        std::swap(rows, other.rows);
        std::swap(cols, other.cols);
    }
};

// Инициализация статической переменной
size_t Matrix::numberOfAllocations = ___18___;

//-----------------------------------------------------------------------------
// Функции для тестирования
//-----------------------------------------------------------------------------

// Функция, возвращающая матрицу по значению 
Matrix createIdentity(size_t size) {
    Matrix result(size, size);
    for (size_t i = 0; i < size; ++i) {
        result.at(i, i) = 1;
    }
    return result;  // Здесь должен сработать ___19___
}

// Функция для проверки корректности копирования
void testCopySemantics() {
    Matrix a(3, 3, 5);
    Matrix b = a;  // Должен вызваться ___20___
    
    b.at(0, 0) = 100;
    
    std::cout << "a[0,0] = " << a.at(0, 0) << "\n";   // Будет выведено ___21___
    std::cout << "b[0,0] = " << b.at(0, 0) << "\n";   // Будет выведено ___22___
}

// Функция для проверки перемещения
Matrix testMoveSemantics() {
    Matrix temp(10, 10, 42);
    Matrix moved = std::move(temp);  // Должен вызваться ___23___
    
    std::cout << "В temp " << temp.getSize() << " элементов\n"; // Будет выведено ___24___
    return moved;  // Здесь должен сработать ___25___
}

//-----------------------------------------------------------------------------
// Основная функция 
//-----------------------------------------------------------------------------

int main() {
    
    Matrix m1;  // Должен вызвать ___26___
    Matrix m2(5, 5, 1);  // Должен вызвать ___27___
        
    m2 = m2;  // Должен корректно обработать ___28___
    
    m1 = std::move(m2);  // Должен вызвать ___29___
    
    Matrix arr[2]; // Должен вызвать ___30___
    arr[0] = Matrix(4, 4, 7);  // Должен вызвать ___31___ затем ___32___
    arr[1] = std::move(Matrix(5, 5, 8));  // Должен вызвать ___33___ затем ___34___
        
    std::cout << "Память была выделена: " << Matrix::getAllocationCount() << " раз\n";
    
    return 0;
}