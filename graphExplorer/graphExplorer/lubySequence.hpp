//
//  lubySequence.hpp
//  graphExplorer
//
//  Created by Francesco Quinzan on 06.09.17.
//  Copyright © 2017 Francesco Quinzan. All rights reserved.
//

#ifndef lubySequence_hpp
#define lubySequence_hpp

#include <vector>
#include <limits>
#include <thread>
#include "EA.hpp"

using namespace std;

/* overloaded vector to compute the sum */
class vec : public std::vector<unsigned long>{
    
public :
    
    unsigned long sum(){
        unsigned long sum = 0;
        if(std::vector<unsigned long>::size() != 0){
            for(unsigned long i = 0; i < std::vector<unsigned long>::size(); i++)
                sum = sum + std::vector<unsigned long>::at(i);
        }
        return sum;
    }

};

class ls{

//public :
    
    /* variables for Luby sequence */
    class EA * alg;
    unsigned long maxStep;
    class vec sequence;
    
    /* make actual Luby Sequence */
    void makeSequence();
    
    
public:
    
    ls(class EA * EA, unsigned long maxStep){
        ls::alg = EA;
        ls::maxStep = maxStep;
        ls::makeSequence();
    }
    
    void run(std::vector<unsigned long> *);

};

#endif /* lubySequence_hpp */
