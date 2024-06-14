#ifndef MATH_HELPER
#define MATH_HELPER
#include <stdio.h>
#include <math.h>

double toPercentage(double dec){
    return dec * 100;
}

//Calculate probability of an event happening
double probability(double probSuccess, double totalAttempts){
    double probFailure = 1 - probSuccess;
    double totalFailure = pow(probFailure, totalAttempts);
    return 1 - totalFailure;
}




#endif