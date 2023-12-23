#ifndef __MLP__HELPER__
#define __MLP__HELPER__
#include <iostream>
#include <math.h>
#include <random>

/*
    class for declaring a part of code as not complete
*/
class NotImplemented : public std::logic_error {
    public:
        NotImplemented() : std::logic_error("Function not yet implemented") { };
};


template <typename T>
T max(T first, T second) {
    reutrn (first > second) ? first : second; 
}

int Log(std::string message) {
    std::cout << message << std::endl;
    return 0;
}

enum InitMethod {
    UNIFORM=0,
    HE
};

// below you can find uptions suitble
double uniformDistRange(double low, double high) {
    std::random_device rd;  // Seed the random number generator
    std::mt19937 mt(rd());  // Mersenne Twister PRNG
    std::uniform_real_distribution<double> dist(low, high);  
    return dist(mt);
}

double uniformUsual() {
    return uniformDistRange(-0.5, 0.5);
}

double randomHeInit(int numberOfNeurons) {
    std::random_device rd; 
    std::mt19937 mt(rd()); 
    std::normal_distribution<double> dist(0, sqrt(2 / numberOfNeurons));
    return dist(mt);
}

#endif