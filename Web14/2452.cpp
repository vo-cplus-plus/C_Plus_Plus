
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    bool transform(string query, string word) {        
        int different = 0;
        for(auto q = query.begin(), w = word.begin(); q!=query.end(); q++, w++) {
            if( *q != *w) different++;
        }        
        return different < 3;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
		for (string& query: queries) {
			for (string& word : dictionary) {				
				if (transform(query, word)) {
					res.push_back(query);
					break;
				}
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