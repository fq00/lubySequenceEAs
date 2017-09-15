//
//  EA.cpp
//  graphExplorer
//
//  Created by Francesco Quinzan on 29/11/2016.
//  Copyright © 2016 Francesco Quinzan. All rights reserved.
//

#include "EA.hpp"

/* run algorithm */
int EA::run(std::vector<unsigned long> *solution, unsigned int seed){
    
    try{
        
        auto flag = 0;
        unsigned long fX, fY;
        
        /* set fitness and initial generator */
        EA::generator.seed(seed);
        class fitness fitness(EA::graph);
        
        if (EA::uniformMutation(individuals::getX()) != -1){
            
            /* compute mutation the first time */
            fX = fitness.f(individuals::getX());
    
            unsigned long t = 1;
            while (t < EA::maxStep){
        
                /* perform mutation */
                if(EA::uniformMutation(individuals::getX(), individuals::getY()) != 0){
                    flag = -1;
                    break;
                }
        
                /* discard worst element */
                fY = fitness.f(individuals::getY());
                if(fX >= fY){
                    individuals::getX()->swap(*individuals::getY());
                    fX = fY;
                };
        
                /* step increase */
                t++;
                
            }
    
            /* return fitness and vertex cover size */
            if(flag != -1){
                solution->push_back(fX);
            }
    
            return flag;
        
        }
        else
            return -1;
    }
    catch(...){
        std::cout << "Exception while running algorithm" << std::endl;
    }
    return -1;
    
};

/* generate an array uniformly at random */
int EA::uniformMutation(std::vector<bool> *x){
    
    try{
        /* prepare for mutation */
        std::vector<bool>().swap(*x);
        long double mutationRate = std::pow(2.0, -1.0);
        
        /* create uniform array */
        for(unsigned long i = 0; i < EA::graph->numberNodes; i++){
            if (EA::uniformReal(1.0) <= mutationRate)
                x->push_back(true);
            else
                x->push_back(false);
        }
        return 0;
    }
    catch(std::bad_alloc&)
    {
        std::cout << "Out of memory while generating new array" << std::endl;
    }
    catch(...)
    {
        std::cout << "Exception while generating new array" << std::endl;
    }
    return -1;
    
};

/* uniform muation */
int EA::uniformMutation(std::vector<bool> *x, std::vector<bool> *y){
    
    try{
        /* prepare for mutation */
        std::vector<bool>().swap(*y);
        long double uniformProb = std::pow((long double) x->size(), -1.0);
    
        /* perform mutation on y */
        for(std::vector<bool>::iterator it = x->begin(); it != x->end(); ++it){
            if (EA::uniformReal(1.0) <= uniformProb)
                y->push_back(!(*it));
            else
                y->push_back(*it);
        }
        return 0;
    }
    catch (...)
    {
            std::cout << "Exception while introduciong mutation" << std::endl;
    }
    return -1;
    
};
