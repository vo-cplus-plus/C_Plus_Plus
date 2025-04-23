#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<m; k++){
                        if(matrix[i][k]) matrix[i][k] = numeric_limits<int>::max();
                    }
                    for(int k=0; k<n; k++){
                        if(matrix[k][j]) matrix[k][j] = numeric_limits<int>::max();
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == numeric_limits<int>::max() ){
                    matrix[i][j] = 0;
                }
            }
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