//
//  lubySequence.cpp
//  graphExplorer
//
//  Created by Francesco Quinzan on 06.09.17.
//  Copyright © 2017 Francesco Quinzan. All rights reserved.
//

#include "lubySequence.hpp"

/* make the luby sequence */
void ls::makeSequence(){
    
    /* prepare array */
    ls::sequence.clear();
    
    /* additional variables */
    unsigned long temp;
    
    while(ls::sequence.sum() < ls::maxStep){
        for(unsigned long k = 0; k < std::numeric_limits<unsigned long>::max(); k++){
            if(ls::sequence.size() == std::pow(2, k) - 1){
                ls::sequence.push_back(std::pow(2, k - 1));
                break;
            }
            else if((ls::sequence.size() >= std::pow(2, k - 1)) and (ls::sequence.size() < std::pow(2, k) - 1)){
                temp = ls::sequence.at(ls::sequence.size() - std::pow(2, k - 1) + 1);
                ls::sequence.push_back(temp);
                break;
            }
        }
    }
    while(ls::sequence.sum() != ls::maxStep)
        ls::sequence.back() = ls::sequence.back() - 1;
    
    return;
    
};

/* run algorithm */
void ls::run(std::vector<unsigned long> * solution){
    
    std::vector<unsigned long> solution_temp;
    std::vector<unsigned long> solution_arr;
    
    ls::alg->newMaxStep(ls::sequence.at(1));
    solution->clear();
    auto flag = ls::alg->run(solution, std::rand());
    solution_arr.push_back(solution->front());

    if(ls::sequence.size() > 2){
        for(unsigned long i = 1; i < ls::sequence.size(); i++){
        solution_temp.clear();
        ls::alg->newMaxStep(ls::sequence.at(i));
            flag = ls::alg->run(&solution_temp, std::rand());
            
            if(solution->back() > solution_temp.back()){
                solution->swap(solution_temp);
            }            
            
        }
    }
    
    return;

};

