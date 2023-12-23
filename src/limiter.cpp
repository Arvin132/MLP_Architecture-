#include "helper.h"
#include "limiter.h"
#include <cmath>

double sigmoid(double given) {
    return 1.0 / (1.0 + std::exp(given));
}

double ReLU(double given) {
    return max<double>(0.0, given);
}

double stepLimiter(double given) {
    return (given > 0) ? 1 : 0;
}

double softMax(double given) {
    throw NotImplemented();
    return 0.0;

}