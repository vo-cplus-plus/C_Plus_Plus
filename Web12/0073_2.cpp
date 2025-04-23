#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();       
        unordered_set<int> rows; 
        unordered_set<int> columns;  
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for(int i: rows){
            for(int j=0; j<m; j++) matrix[i][j] = 0;
        }
        for(int j: columns){
            for(int i=0; i<n; i++) matrix[i][j] = 0;
        }          
    }
    void print(vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main(){
    vector<vector<int>> matrix({{1,0,1},{1,2,3},{0,1,4}});
    Solution s;
    s.setZeroes(matrix);
    s.print(matrix);
}