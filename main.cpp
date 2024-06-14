#include "src/tools/MathHelper.h"
#include <iostream>
#include <random>
#include <chrono>
#include "src/modules/base/ArithmeticExec.hpp"


int main(){

    ArithExec* exercise = new ArithExec(false, 1, 10);
    while(true){   
        exercise->generate();
        double ans;
        std::cin >> ans;

        if(exercise->sendAnswer(ans)){
            exercise->fillTerms(4, exercise->lowerInterval, exercise->upperInterval);
        }
        else break;
    }

    char finish;
    std::cin >> finish;
    delete exercise;
}