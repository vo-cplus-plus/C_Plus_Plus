#include <iostream>
#include <cstdlib> // For rand and srand
#include <ctime>   // For time

int main() {
    srand(time(NULL)); // Seed the RNG with the current time
    std::cout << "Random Integer: " << rand() << std::endl;
    return 0;
}