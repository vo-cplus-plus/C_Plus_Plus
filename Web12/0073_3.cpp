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
        bool firstRowChanged = false, firstColChanged = false;
        for(int i=0; i<n; i++) if(matrix[i][0]==0) firstColChanged = true;         
        for(int j=0; j<m; j++)
            if(matrix[0][j]==0)
                firstRowChanged = true;
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0)                      
                    matrix[0][j] = matrix[i][0] = 0;                                    
            }
        }
        for(int i=1; i<n; i++){            
            for(int j=1; j<m; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;                    
                }
            }
        }
        if (firstRowChanged)            
            for(int j=0; j<m; j++) matrix[0][j] = 0;
        if (firstColChanged)
            for(int i=0; i<n; i++) matrix[i][0] = 0;                    
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
    vector<vector<int>> matrix({{1,1,1},{1,0,3},{1,1,4}});
    Solution s;
    s.setZeroes(matrix);
    s.print(matrix);
}