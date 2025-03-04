#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;




int main(){    
    vector<string> names({"Belgian Waffles", "Strawberry Belgian Waffles",
    "Berry-Berry Belgian Waffles", "French Toast", "Homestyle Breakfast"});
    vector<float> prices({5.95, 7.95, 8.95, 4.5, 6.95});
    vector<short> calories({650, 900, 900, 600, 950});
    ofstream output("objects.dat", ios::binary);
    for(int i=0; i<5; i++){
        int len = names[i].length();
        output.write(reinterpret_cast<char*>(&len), sizeof(int));
        output.write(names[i].c_str(), len);
        output.write(reinterpret_cast<char*>(&prices[i]), sizeof(float));
        output.write(reinterpret_cast<char*>(&calories[i]), sizeof(short));
    }
    return 0;

}