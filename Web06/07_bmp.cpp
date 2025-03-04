#include <fstream>
#include <vector>
using namespace std;
using Byte = unsigned char;

long getFileSize(iostream &file);
vector<Byte> getImage (iostream &file, long fileSize);
inline Byte Gray(Byte R, Byte G, Byte B);
void changeImage(vector<Byte> &image);
void writeImage(iostream &file, vector<Byte> &image);

int main(){  
    fstream file("Koala.bmp", ios::binary|ios::in|ios::out);
    auto fileSize = getFileSize(file);
    auto image = getImage(file, fileSize);
    changeImage(image);
    writeImage(file, image);
    return 0;
}

long getFileSize(iostream &file){
    // отправляем маркер в конец файла
    file.seekg(0, ios::end);
    // узнаем, сколько байт от начала файла до текущего положения маркера
    // это равно размеру файла в байтах
    return file.tellg();
}

vector<Byte> getImage(iostream &file, long fileSize){
    long size = fileSize - 54; // 54 - размер заголовков
    // выделяем область памяти в которой будем хранить данные
    char * data = new char[size]; 
    // сбрасываем флаги состояния к исходным значениям
    file.clear(); 
    // переводим маркер чтения в начало раздела данных
    file.seekg(54, ios::beg);
    // считываем данные
    file.read(data, size);
    // создаем вектор на этих данных
    vector<Byte> values(data, data + size);
    return values;
}

Byte Gray(Byte R, Byte G, Byte B){
    return R * 0.257 + G * 0.504 + B * 0.098 + 16.0; 
}

void changeImage(vector<Byte> &image){
    for(int i=0; i<image.size(); i+=3){
        Byte red = image[i+2]; 
        Byte green = image[i+1];
        Byte blue = image[i];
        Byte gray = Gray(red, green, blue);
        image[i] = gray;
        image[i + 1] = gray;
        image[i + 2] = gray;
    }    
}

void writeImage(iostream &file, vector<Byte> &image){
    file.clear(); 
    // переводим маркер записи в начало раздела данных
    file.seekp(54, ios::beg);
    // считываем данные
    file.write(reinterpret_cast<char*>(image.data()), image.size());
}