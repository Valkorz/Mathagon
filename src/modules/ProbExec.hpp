#include "../src/Quiz.hpp"

class ProbExec : public Quiz{
    const std::string PATH = "./models/probability/";
    
    public: 
        ProbExec(bool predef = false) : Quiz(predef)
        {
            this->type = prob;
        }
        double generate() override{
            if(this->predef){

            } else {
                //TODO
            }
        }
};