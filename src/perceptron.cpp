#include "perceptron.h"

Perceptron::Perceptron(double init, double (*limiter)(double)): value(init), limiter(limiter) {}


double Perceptron::setValueUsingLimiter(double given) {
    value = limiter(given);
    return value;
}

double Perceptron::getValue() { return value; }

void Perceptron::setLimiter(double (*newLimiter)(double)) {
    limiter = newLimiter;
}

