#include <fstream>
#include <vector>
using namespace std;

int main(){       
    // вектор
    vector<double> values({2.6, 4.8, 4.2, -2.8, -1.2, -1.6, 1.2, -5.5, -6.1, -6.6}); 
    ofstream output("values.dat", ios::binary);
    output.write(reinterpret_cast<char *>(values.data()), sizeof(double) * values.size());
}