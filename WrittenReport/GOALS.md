Leading Question: We will use a LLVM assembly code dataset to visualize code performance and run algorithms on the assembly code, including a shortest path and identifying loop nests.

Dataset Acquisition and Processing: The dataset for this project will be acquired by running source code from some sample program. We will use the emit command to produce LLVM assembly code, which will be used as the aforementioned dataset. Using the assembly instructions, we will create a graph using basic blocks as nodes. The order of nodes will be defined by the assembly code’s control flow. We will make sure to always use working code that compiles, so we do not expect to have incomplete datasets. The graph will be created using an array implementation and an adjacency list.

Graph Traversals:
* We will use a DFS traversal that detects back edges to find individual loops.

Graph Algorithms: 
1. Finding loop nests by identifying strongly connected components. For this, we will use Dijkstra's path-based strong component algorithm (https://en.wikipedia.org/wiki/Path-based_strong_component_algorithm). This algorithm will take the generated control-flow graph as the input, and will return all of the strongly connected components in O(n) time, where n is the number of vertices. Identifying loop nests in a control flow graph is important in compiler design, as they are often a prime target for optimization.
2. Calculate performance by adding weights to edges and finding shortest paths from the root. We will use Dijkstra's shortest path algorithm, which will take the control flow graph as an input, then output the shortest path between a node and the root. In an array, this will run in O(n^2), where n is the number of vertices. We will assign initial weights to each edge depending upon the number of instructions in the basic block and the type of instructions in the basic block. This will allow us to predict the runtime of a certain program before it even runs, and in the future compare against various flags and compilers to see how a compiler optimizes their program.

Other possible work:
1. Visualization of the graph 
2. Compare what compiler optimization and flags does to the graph
3. Compare with other compilers (G++)
4. Big-O performance estimator

Timeline: 
- Data Acquisition: 11/15/21
- Data Processing: 11/22/21
- Algorithm 1: 11/29/21
- Algorithm 2: 12/6/21
- Final Project Working: 12/13/21
