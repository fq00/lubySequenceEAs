//
//  inputManager.cpp
//  graphExplorer
//
//  Created by Francesco Quinzan on 29/11/2016.
//  Copyright © 2016 Francesco Quinzan. All rights reserved.
//

#include "inputManager.hpp"

/* parse a character array */
void graph::addEdge(char line[256]){
    
    try{
        char * ptEnd = NULL;
        std::vector<unsigned long> parseString;
    
        parseString.push_back((unsigned long)std::strtol(line, &ptEnd, 10));
        parseString.push_back((unsigned long)std::strtol(ptEnd, NULL, 10));
        graph::adjList.push_back(parseString);
    
        return;
    }
    catch(std::bad_alloc&)
    {
        std::cout << "Out of memory while importing graph" << std::endl;
        exit (EXIT_FAILURE);
    }
    catch(...){
        std::cout << "Exception while importing graph" << std::endl;
        exit (EXIT_FAILURE);
    }
    
};

/* import graph data from text file */
void graph::import(std::string fileName){
    
    try{
        std::ifstream file;
        char line[256];
    
        file.open(fileName);
        while (file.getline(line, 256))
            graph::addEdge(line);
    
        return;
    }
    catch(...){
        std::cout << "Exception while reading input file" << std::endl;
        exit (EXIT_FAILURE);
    }
};

/* get number of edges and number of nodes */
void graph::setVariables(){
    
    try{
        
        /* get number of nodes */
        graph::numberNodes = 0;
        if (graph::adjList.size() != 0){
            for(std::vector<std::vector<unsigned long> >::iterator it = graph::adjList.begin(); it != graph::adjList.end(); ++it){
                if(graph::numberNodes < std::max(it->front(), it->back()))
                    graph::numberNodes = std::max(it->front(), it->back());
            }
        }
        graph::numberNodes++;
    
        /* get number of edges */
        graph::numberEdges = graph::adjList.size();

        return;
    }
    catch(...){
        std::cout << "Exception while setting graph variables" << std::endl;
        exit (EXIT_FAILURE);
    }
    
};

