#ifndef __MLP_LIMITER__
#define __MLP_LIMITER__

enum LimiterType {
    SIGMOID=0,
    RELU,
    STEP
};

double sigmoid(double given);

double ReLU(double given);

double stepLimiter(double given);

double softMax(double given);
#endif