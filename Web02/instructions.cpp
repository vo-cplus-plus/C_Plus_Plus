#include <iostream> // подключение библиотеки ввода / вывода
#include <fstream> // подключение библиотеки для работы с файлами

using namespace std;

#include <iostream>

int main(){
    unsigned char a = 250;
    unsigned char b = 150;
    unsigned char res =  a + b;
    int k=0;
    for(int i=500; i>0; i/=2, k++);
    return 0;
}



int main1(){    

    
    auto a = 10, b = 5;
    // разветвление
    if (a > b && (a % 2 == 0 || b % 2 != 0)) cout << a << endl; 
    else cout << b << endl;

    // цикл с предусловием
    while (a > 0){
        a--;
        b *= 2;
    }
    cout << a << " " << b << endl;

    // цикл с фиксированным количеством итераций
    int s = 0;
    for(int i=0; i< 10; i++ ){
        s += i;
    }
    cout << s << endl;
    return 0;
}

