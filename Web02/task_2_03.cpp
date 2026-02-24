#include <iostream>


int main(){
    char c = 'o';
    bool res = false;
    int i = 0;
    if ('a' <= c &&  c<= 'z'){
        switch (c)
        {
        case 'a': i++;
        case 'e': i++;
        case 'i':i++;
        case 'o':i++;
        case 'u':i++;
        case 'y':i++;
            res = true;
            break;
        
        default:
            break;
        }
    }
}