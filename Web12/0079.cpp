#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include <unordered_set>
#include <memory>
using namespace std;

class Solution {
    // указатель на матрицу
    vector<vector<char>>* pBoard;
    // указатель на слово
    string* pWord;
    // множество посещенных ячеек по из порядковому номеру
    unordered_set<int> visited;
    int n, m;
public:
    bool dfs(int i, int j, int k){  
        // вычисляем текущее положение
        int pos = i * m + j;      
        // если просмотрели все буквы слова, то слово найдено
        if (k == pWord->length()) return true;
        // в слове есть непроверенные буквы
        // вышли за пределы матрицы - здесь слова нет
        if (i < 0 || i >= n || j < 0 || j >= m) return false;
        // пытаемся обратиться к уже просмотренной ячейке - здесь слова нет
        if (visited.count(pos) != 0) return false;
        // не нашли требуемую букву - здесь слова нет
        if ((*pBoard)[i][j] != (*pWord)[k]) return false;
        // нашли k-ую букву
        // запоминаем текущее положение    
        visited.insert(pos);
        // результат поиска - результат поиска следюЩИХ букв 
        // в соседних ячейках
        bool res = dfs(i+1, j, k+1) || dfs(i-1, j, k+1) ||
                   dfs(i, j+1, k+1) || dfs(i, j-1, k+1);
        // откатываемся назад
        visited.erase(pos);
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // запоминаем адреса аргументов
        pBoard = &board;
        pWord = &word;
        n = board.size();
        m = board[0].size();
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                // если нашли, где начинается слово
                if (board[i][j] == word.front()){
                    if (dfs(i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};
int main(){    
    vector<vector<char>> pBoard ({{'A','B','C','E'},
                                 {'S','F','C','S'},
                                 {'A','D','E','E'}});
    Solution s;
    if (s.exist(pBoard, "ABCCED")){
        cout << "Строка есть в матрице\n";
    }else{
        cout << "Строки нет в матрице\n";
    }
    
}