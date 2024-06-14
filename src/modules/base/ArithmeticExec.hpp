
#include "../../tools/MathHelper.h"
#include <math.h>
#include <string.h>
#include <random>
#include <chrono>
#include "../../Quiz.hpp"
#include <iostream>

class ArithExec : public Quiz{

    public:
        char sign;
    
        ArithExec(bool predef = false, float lowerInterval = 1, float upperInterval = 2) 
        : Quiz(predef, lowerInterval, upperInterval){
            type = basic;
            fillTerms(4, lowerInterval, upperInterval);
        }
        double generate() override{
            int num = getRandomInt(0, 5);
            switch(num){
                case 0:
                    sign = '+';
                    answer = placeholders[0] + placeholders[1];
                    break;
                case 1:
                    sign = '-';
                    answer = placeholders[0] - placeholders[1];
                    break;
                case 2:
                    sign = '*';
                    answer = placeholders[0] * placeholders[1];
                    break;
                case 4:
                    sign = '/';
                    answer = placeholders[0] / placeholders[1];
                    break;
                case 5:
                    sign = '^';
                    answer = pow(placeholders[0], placeholders[1]);
                    break;
            }

        std::cout << "\n" << placeholders[0] << sign << placeholders[1] << std::endl;
        }
};

