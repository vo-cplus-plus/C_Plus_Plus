#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> temp(matrix);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(temp[i][j] == 0){
                    for(int k=0; k<m; k++){
                        matrix[i][k] = 0;
                    }
                    for(int k=0; k<n; k++){
                        matrix[k][j] = 0;
                    }
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