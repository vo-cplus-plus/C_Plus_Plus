#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

using matrix = vector<vector<double>>;
using vec = vector<double>;

void forward_steps(matrix &A, vec &b) {
    int n = A.size();
    for (int i = 0; i < n; i++) {        
        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] -= factor * A[i][k];                  
            }
            b[j] -= factor * b[i];                
        }
    }
}

vec backward_steps(matrix &A, vec &b) {
    int n = A.size();
    vec x(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = b[i];
        for (int j = i+1; j < n; j++) {
            sum -= A[i][j] * x[j];
        }
        x[i] = sum / A[i][i];
    }
    return x;
}

vec gauss(matrix &A, vec &b){
    forward_steps(A, b);
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A.size(); j++){
            cout<< fixed <<setprecision(3) << A[i][j] << " " ;
        }
        cout << endl;
    }
    return backward_steps(A, b);
}

matrix get_random_matrix(int n, std::random_device &rnd_device){
    std::uniform_real_distribution<double> dist(1.0, 100.0);
    matrix A(n, vec(n));
    for(int i=0; i<n; i++){        
        for(int j=0; j<n; j++){
            A[i][j] = dist(rnd_device);            
        } 
    }
    return A;
}

matrix get_matrix(int n){
    matrix A(n, vec(n));
    for(int i=0; i<n; i++){        
        for(int j=0; j<n; j++){           
            A[i][j] = 1.0 / (i + j + 1);
        } 
    }
    return A;
}

vec multiply(matrix &A, vec &x){
    int n = A.size();
    vec res(n, 0);
    for(int i=0; i<n; i++){        
        for(int j=0;j<n;j++){
            res[i] += A[i][j] * x[j];
        }        
    }
    return res;
}

double get_error(vec &x0, vec &x){
    int n = x.size();
    double res = 0;
    for(int i=0; i<n; i++){        
        res += (x[i] - x0[i]) * (x[i] - x0[i]);
    }
    return sqrt(res);
}





int main(){
    std::random_device rnd_device;    
       
    int n = 10;
    matrix A = get_random_matrix(n, rnd_device);
    matrix _A = get_matrix(n);
    matrix cA(A), _cA(_A);

    vec x0(n, 1);
    vec b = multiply(A, x0);
    vec _b = multiply(_A, x0);
    
    auto x = gauss(A, b);
    auto _x = gauss(_A, _b);
    cout << "Погрешность при случайной матрице: " << get_error(x0, x) << endl;
    cout << "Погрешность при плохо обусловленной матрице: " << get_error(x0, _x) << endl;
}



