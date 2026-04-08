#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

struct KeyItem{
    int key;
    string name;
    friend ostream & operator << (ostream &out, const KeyItem &item){
        out << item.key << " " << item.name;
        return out;
    } 
    bool operator == (const KeyItem &item)const{
        return key == item.key && name == item.name;
    }   
};
template <>
struct std::hash<KeyItem>
{
  std::size_t operator()(const KeyItem& item) const
  {
    return (hash<int>()(item.key)
          ^ hash<string>()(item.name));
  }
};
struct ValueItem{
    double value;
    string name;
    friend ostream & operator << (ostream &out, const ValueItem &item){
        out << item.value << " " << item.name;
        return out;
    }
};

int main() {
    unordered_map<KeyItem, ValueItem>m(
        {pair(KeyItem{5, "5K"},ValueItem{0.5, "5V"}),
         pair{KeyItem{1, "1K"},ValueItem{0.1, "1V"}},
         pair{KeyItem{3, "3K"},ValueItem{0.3, "3V"}}});

    for(auto it = m.begin(); it!=m.end(); it++){
        cout << it->first << " -> " << it->second<< endl;
    }  
    /*cout << endl;
    for(auto it = m.rbegin(); it!=m.rend(); it++){
        cout << it->first << " -> " << it->second<< endl;
    }  */ 
}