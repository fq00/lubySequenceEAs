# lubySequenceEAs
## Abstract
In the context of black box optimization, the most common way to handle deceptive attractors is to periodically restart the algorithm. To derive the optimal restart time of a black-box algorithm, perfect knowledge of the convergence probability function is necessary. This quantity is often unknown or difficult to compute. We test performance of various algorithms, follwing a universal strategy that does require any tuning proceadure.
We conisder a dataset taken from SNAP (Stanford Network Repository Analysis), that consists of a portion of the Facebook. We perform extensive testing on this dataset for a commonly used EA, and the same algorithm with a universal restart strategy. We perform the analysis for fixed time budget and look at the overall approximation ratio. 

## Algorithms

The (1 + 1)-EA is a search heuristics inspired by the process of natural selection. Typically, it requires as input a population of strings of fixed length n. After an offspring is generated, a mutation factor is introduced, to ensure full objective space exploration. The fitness is then computed, and the less desirable result is discarded.

## Files and folders
The project is organized as follows.

* experiments = Python files to manage the experiments, along with the results
* graphExplorer = The C++ source kernel

## Conclusions
In this paper we adapt the work on optimal restart strategies by Luby et. al. to the average case black box complexity of heuristic optimization techniques. We focus on elitist algorithms. We consider the Minimum Vertex Cover problem (MVC) for real-world networks, and show that the (1+1)EA with restarts performs significantly better than the EA without restarts.
