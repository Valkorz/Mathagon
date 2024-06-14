#ifndef QUIZ_CLASS
#define QUIZ_CLASS
#include "tools/MathHelper.h"
#include <string.h>
#include <random>
#include <chrono>
#include <iostream>

class Quiz{
    
    const std::string PATH = "./";
    
    public:

        enum Type{
            none,
            basic,
            prob,
            trig,
            alge,
        };

        Type type;
        bool predef;
        double* placeholders;
        double answer;
        double lowerInterval, upperInterval;
        std::string question;

        Quiz(bool predef = false, float lowerInterval = 1, float upperInterval = 2){
            this->predef = predef;
            this->lowerInterval = lowerInterval;
            this->upperInterval = upperInterval;
        }
        virtual double generate() = 0;

        void fillTerms(int count, float lowerInterval, float upperInterval){
          
            placeholders = new double[count];
            for(int i = 0; i < count; i++){
                std::cout << i << std::endl;
                placeholders[i] = getRandom(lowerInterval, upperInterval, i);
            }
        }

        double getRandom(float lowerInterval, float upperInterval, int i = 0){
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count() + i;
            std::mt19937 gen(seed); // Standard mersenne_twister_engine seeded with rd()
            std::uniform_real_distribution<> rand(lowerInterval, upperInterval);
            return rand(gen);
        }

        int getRandomInt(int lowerInterval, int upperInterval){
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::mt19937 gen(seed); // Standard mersenne_twister_engine seeded with rd()
            std::uniform_int_distribution<> rand(lowerInterval, upperInterval);
            return rand(gen);
        }

        bool sendAnswer(double ans){
            if(ans == answer){
                std::cout << "You're right!" << std::endl;
                return true;
            }
            else{
                std::cout << "The corrent answer was: " << answer << std::endl;
                return false;
            }
        }

        double replace(char* text){          
            int repCount = 0;
            for(int i = 0; i < strlen(text); i++){
                if(text[i] == '@'){
                    repCount++;
                }
            }

            placeholders = new double[repCount];
            std::string new_text;


            for(int i = 0, e = 0; i < strlen(text); i++){
                if(text[i] == '@'){
                    std::string rnd_num_str = std::to_string(placeholders[e]);
                    new_text += rnd_num_str;
                    e++;
                }
                else {
                    new_text += text[i];
                }
            }

        }

        ~Quiz(){
            delete[] placeholders;
        }
        
};


#endif