#include <fstream>
#include <vector>
using namespace std;

int main(){  
    ifstream input("values.dat", ios::binary);
    // отправляем маркер в конец файла
    input.seekg(0, ios::end);
    // узнаем, сколько байт от начала файла до текущего положения маркера
    // это равно размеру файла в байтах
    auto fileSize = input.tellg();
    // выделяем область памяти в которой будем хранить данные
    char * data = new char[fileSize];
    // сбрасываем флаги состояния к исходным значениям
    input.clear(); 
    // переводим марке в начало файла
    input.seekg(0, ios::beg);
    // считываем данные
    input.read(data, fileSize);
    // создаем вектор на этих данных
    vector<double> values(reinterpret_cast<double*>(data), reinterpret_cast<double*>(data) + fileSize / sizeof(double));
    return 0;
}