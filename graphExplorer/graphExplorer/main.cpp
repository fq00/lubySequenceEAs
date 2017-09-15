//
//  main.cpp
//  graphExplorer
//
//  Created by Francesco Quinzan on 29/11/2016.
//  Copyright © 2016 Francesco Quinzan. All rights reserved.
//

#include <iostream>
#include <vector>

#include "inputManager.hpp"
#include "EA.hpp"
#include "lubySequence.hpp"


using namespace std;

int main(int argc, const char * argv[]) {
    
    if(argc == 5){
        
        /* import graph */
        std::string file = argv[2];
        class graph graph(file);
        std::vector<unsigned long> solution;
        
        /*  choose algorithm */
        std::string algr = argv[1];
        
        if(algr == "EA"){
        
            /* initialize and run EA */
            class EA EA(&graph,  atol(argv[3]));
            if (EA.run(&solution, atol(argv[4])) != -1){
                
                std::cout << " " << solution.at(0);
                
            }
            else
                
                std::cout << "process aborted" << std::endl;
            
        }
        else if (algr == "EAU"){
            
            /* initialize EA */
            class EA EA(&graph,  1);
            std::srand(atol(argv[4]));
        
            /* intialize and run Luby Sequence */
            class ls ls(&EA, atol(argv[3]));
            ls.run(&solution);
            
            /* return best solution */
            std::cout << " " << solution.at(0);
            
        }
        
        
        
        
    }
    else {

        std::cout << "wrong command" << std::endl;
        
    }
    
    return 0;
}
