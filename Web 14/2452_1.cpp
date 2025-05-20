
#include <vector>
#include <string>
#include <memory>
#include <iostream>
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

    static bool searchTransformWord( shared_ptr<Node> node, string word, int count, int index) {
        if (count > 2) return false;
		if (index == word.length()) {
			return count <= 2;
		}
		bool res = false;
        int i=0;
        for(auto child = node->children.begin(); child != node->children.end(); child++, i++){
            if (*child){
                int diff = 0;
                if (word[index] - 'a' != i) diff = 1;
                res = res || searchTransformWord(*child, word, count + diff, index + 1);
            }
        }		
		return res;
	}
    bool searchTransformWord(string word) {
        return searchTransformWord(root, word, 0, 0);
    }    
};

class Solution {
private:
    Trie trie; 
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        // создание дерева
		for (string& word : dictionary) {
			trie.insert(word);
		}
        // проверка запросов
		for (string& query : queries) {			
			if (trie.searchTransformWord(query)) {
				res.push_back(query);
			}
		}
		return res;
    }
};

int main(){
    Solution s;
    vector<string> queries = {"word","note","ants","wood"}, dictionary = {"wood","joke","moat"};
    auto res = s.twoEditWords(queries, dictionary);
    return 0;
}

