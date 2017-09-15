# lubySequenceEAs
## Abstract
In the context of black box optimization, the most common way to handle deceptive attractors is to periodically restart the algorithm. To derive the optimal restart time of a black-box algorithm, perfect knowledge of the convergence probability function is necessary. This quantity is often unknown or difficult to compute. We test performance of various algorithms, follwing a universal strategy that does require any tuning proceadure.
We conisder a dataset taken from SNAP (Stanford Network Repository Analysis), that consists of a portion of the Facebook. We perform extensive testing on this dataset for a commonly used EA, and the same algorithm with a universal restart strategy. We perform the analysis for fixed time budget and look at the overall approximation ratio. 

## Algorithms

The (1 + 1)-EA is a search heuristics inspired by the process of natural selection. Typically, it requires as input a population of strings of fixed length n. After an offspring is generated, a mutation factor is introduced, to ensure full objective space exploration. The fitness is then computed, and the less desirable result is discarded.

The greedy algorithm is deterministic, and it is specifically designed to find a minimum vertex cover of an input graph. It iteratively adds nodes, which have highest degree to the cover, until all edges are covered.


## Files and folders
The project is organized as follows.

* experiments = Python files to manage the C++ executable
* graphExplorer = The C++ source kernel
* graph = all input graphs for the experiments
* results = all experimental results, including R postprocess files

## Conclusions
We looked at the approximation ratio and run time analysis of single-objective EAs, for well known NP-hard problems on the graphs with deterministic PLB properties, and the power-law exponent β > 2. We analyze the (1+1) EA for the maximum dominating set, maximum vertex cover and connected dominating set problems. We show that the (1+1) EA obtain constant-factor approximation ratio within polynomial run time.
We observe experimentally that the (1+1) EA always produces better results than the greedy algorithm for the minimum vertex cover problem. We showthat the (1+1) EA gives better approximation ratio than greedy on the Chung-Lu and Hyperbolic model. We observe that on the Hyperbolic model the (1+1) EA reaches better approximation ratio than in the Chung-Lu case. We give a worst case instance with the PLB properties, where greedy algorithm obtain an optimal solution, but the (1+1) EA gives worst possible solution with constant probability. We conclude that the EAs for the above-mentioned problems on the graphs with PLB properties and β > 2, obtain better approximation than the known worst-case approximation. This implies that topological properties of real-world instances play an important role in the performance of EAs.
