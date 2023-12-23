#ifndef __MLP__PRECEPTRON__
#define __MLP__PRECEPTRON__
/*

    Perceptron Class is an object that takes and hold two values:
        1- value of sum of weights that has been filtered by the limiter
        2- pointer to the limiter function which is either:
            a- sigmoid function
            b- ReLU

*/


class Perceptron {
    double value;
    double (*limiter)(double);

    public:
        double setValueUsingLimiter(double given);
        double getValue();
        void setLimiter(double (*newLimiter)(double));
        Perceptron(double init, double (*limiter)(double)); 
};

#endif