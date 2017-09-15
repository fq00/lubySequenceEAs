//
//  EA.hpp
//  graphExplorer
//
//  Created by Francesco Quinzan on 29/11/2016.
//  Copyright © 2016 Francesco Quinzan. All rights reserved.
//

#ifndef EA_hpp
#define EA_hpp

#include <stdio.h>
#include <random>
#include <math.h>
#include "inputManager.hpp"
#include "fitness.hpp"

using namespace std;

class individuals {

protected:
    
    std::vector<bool> x;
    std::vector<bool> y;
    
public:
    
    std::vector<bool> * getX(){return (&x);};
    std::vector<bool> * getY(){return (&y);};

};

class EA : public individuals {
    
    /* graph to solve */
    struct graph *graph;
    
    /* algorithm parameters */
    unsigned long maxStep;
    unsigned long problemSize;
    
    /* random number generator and distribution */
    std::mt19937 generator;
    inline long double uniformReal(long double x){
        std::uniform_real_distribution<long double> uniformRealDistribution(0.0, x);
        return(uniformRealDistribution(EA::generator));
    };
    
    /* algorithmic operations */
    int uniformMutation(std::vector<bool> *);
    int uniformMutation(std::vector<bool> *, std::vector<bool> *);
    
    
public:
    
    /* constructor */
    inline EA(class graph *graph, unsigned long maxStep){
        
        /* derived class */
        EA::graph = graph;
        EA::maxStep = maxStep;
        
        /* base class */
        EA::problemSize = EA::graph->numberNodes;
        
    };
    
    /* adjust maxStep */
    void newMaxStep (unsigned long maxStep){
        EA:maxStep = maxStep;
        return;
    }
    
    
    /* run algorithm given random seed */
    int run(std::vector<unsigned long> *, unsigned int);
    
    /* make individual */
    int makeIndividual(){
        for(unsigned long i = 0; i < EA::problemSize; i++){
            if(rand() < 0.5)
                individuals::x.push_back(true);
            else
                individuals::y.push_back(false);
        }
        return 0;
    }
    
};


#endif /* EA_hpp */
