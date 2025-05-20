#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>
using namespace std;

class Book {
public:
    Book(){}
    ~Book(){}
private:
    struct Content; // Объявление реализации без деталей
    unique_ptr<Content> pContent; // Указатель на реализацию
};

class Book::Content{
    vector<string> content;
    string autor;
    string title;
};