#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct RGB {
    int red, green, blue;
    RGB(int r, int g, int b) : red(r), green(g), blue(b) {}
};

class Darken{
    double factor;
    RGB darken(const RGB& color) {
    return RGB(color.red * factor,
               color.green * factor,
               color.blue * factor);
}
public:
    Darken(float f):factor(f){}
    pair<string, RGB> operator()(const pair<string, RGB> & color) {
        return pair<string, RGB>{color.first, darken(color.second)};
    }
};

void print(const map<string, RGB> &colors){
    cout << "Цвета:\n";
    for (const auto& [name, rgb] : colors) {
        cout << name << ": " << "(" << rgb.red << ", "
             << rgb.green << ", " << rgb.blue << ")\n";
    }
}

int main() {    
    map<string, RGB> colors = {
        {"red", RGB(255, 0, 0)},
        {"green", RGB(0, 255, 0)},
        {"blue", RGB(0, 0, 255)},
        {"white", RGB(255, 255, 255)},
        {"black", RGB(0, 0, 0)},
        {"yellow", RGB(255, 255, 0)},
        {"cyan", RGB(0, 255, 255)},
        {"magenta", RGB(255, 0, 255)},
        {"silver", RGB(192, 192, 192)},
        {"gray", RGB(128, 128, 128)}
    };
    map<string, RGB> colorsCopy;
    // создаем копию словаря
    copy(colors.begin(),colors.end(),
         inserter(colorsCopy, colorsCopy.end()));
    // создаем новый словарь с более темными оттенками
    map<string, RGB> colorsDark;
    transform(colors.begin(), colors.end(),
               inserter(colorsDark, colorsDark.end()),
               Darken(0.5));
    print(colors);
    print(colorsCopy);
    print(colorsDark);
}