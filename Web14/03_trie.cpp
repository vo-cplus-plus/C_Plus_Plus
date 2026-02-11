#include <iostream>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class Trie {
    // Класс узла дерева
    class Node {
    public:
        bool endofWord;
        vector<shared_ptr<Node>> children;
        
        Node():endofWord(false){
            // предполагаем возможность любой следующей буквы
            children.resize(26);            
        }
    };
private:
    shared_ptr<Node> root;

public:
    Trie() {root = make_shared<Node>(Node());}

    // Добавление слова в дерево
    void insert(string word)
    {
        shared_ptr<Node> node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = make_shared<Node>(Node());
            }
            node = node->children[index];
        }
        node->endofWord = true;
    }

    // Определяет, есть ли слово в префиксном дереве
    bool search(string word){
        shared_ptr<Node> node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return node->endofWord;
    }

    // Исключает слово из префиксного дерева
    // удаляет признак конца слова
    void deleteWord(string word)
    {
        shared_ptr<Node> node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                return;
            }
            node = node->children[index];
        }
        if (node->endofWord) {
            node->endofWord = false;
        }
    }

    // вывод от заданного звена
    void print(ostream & out, shared_ptr<Node> node, string prefix) const
    {
        if (node->endofWord) {
            cout << prefix << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                print(out, node->children[i],
                      prefix + char('a' + i));
            }
        }
    }

    // Оператор вывода
    friend ostream & operator << (ostream & out, const Trie &trie) {
        trie.print(out, trie.root, "");
        return out;
    }
};

int main()
{    
    Trie trie;

    // Добавим слова
    trie.insert("key");
    trie.insert("keys");
    trie.insert("keyword");
    trie.insert("access");
    trie.insert("accurate");
    trie.insert("apply");

    // Выведем на экран
    cout << "Префиксное дерево:" << endl;
    cout << trie << endl;

    // Поиск
    cout << "\nРезультаты поиска:" << endl;
    cout.setf(ios::boolalpha);
    cout << "access: " << trie.search("access") << endl;
    cout << "application: " << trie.search("application") << endl; 

    // Удалим слова
    trie.deleteWord("keys");
    trie.deleteWord("accurate");

    // Выведем на экран
    cout << "\nПрефиксное дерево после удаления:" << endl;
    cout << trie << endl;
}