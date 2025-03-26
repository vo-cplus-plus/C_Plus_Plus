#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Book;
class Library{
    string name;
    vector<Book> books;
public:
    Library(const string name):name(name){}
    vector<Book>& getBooks(){return books;}
    void addBook(Book &&book){
        books.push_back(book);
    }
    string& Name(){return name;}
};

class Book{
    Library &library;
    string name;
    string author;
    int year;
public:
    Book(Library &library, string name, string author, int year):library(library), name(name), author(author), year(year){}
    friend ostream & operator << (ostream & out, const Book&book){
        out <<"В библиотеке " << book.library.Name() << " книга " << book.name << " " << book.author <<" " << book.year;
        return out;
    }
};

int main(){
    Library lib("городская библиотека");
    lib.addBook(Book(lib, "Язык программирования C++", "Бьёрн Страуструп", 1986));
    lib.addBook(Book(lib, "Война и мир", "Л.Н. Толстой", 2021));
    for (auto& book : lib.getBooks()){
        cout << book << endl;
    }
}