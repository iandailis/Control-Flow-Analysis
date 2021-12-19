
	The objective for our final project was to visualize code performance and running algorithms on a control flow graph 
	generated from an LLVM assembly code dataset. These algorithms included both identifying the shortest possible path 
	from the source node and identifying loop nests within the code. As a result, the main goals for this project were 
	to use a depth-first search to traverse through the graph to find back edges and to find individual loops, to find 
	loop nests using Tarjan’s path-based strong component algorithm (as it returns strongly connected components), and 
	to use Dijkstra’s shortest path algorithm to calculate performance by adding weights to each edge and finding shortest 
	paths from the root to all other nodes. 
	
	Conveniently for the rest of the group, all the main goals listed in the proposal ultimately worked out as intended, 
	although a few additional possible plans were also included to aid in some of the goals.  Along with the inclusion of
	extra steps to achieve the main goals, there was also the creation of the graph’s visualization. In order to achieve 
	this, the visualization of the graph was created from the .DOT graph description language, which was then parsed into 
	a text file using a script written in Python. Both the algorithms (Dijkstra’s shortest path and Tarjan’s strongest 
	connected components) and the DFS traversal were confirmed to work by comparing the output graph to the .DOT visualization.
	
	The Dijkstra’s shortest path algorithm was created by implementing the standard algorithm. However, we faced trouble 
	when implementing the priority queue, as priority queues order values in an increasing order, however, we want edges 
	with lower weights to have higher priority. To fix this, we made the weights negative in the queue to have the weights 
	with the largest values appear at the end. The runtime for this algorithm was O(|E| + |V|log(|V|)).
	
	The Tarjan’s strongest component algorithm was similarly created by implementing a standard algorithm. The largest problem 
	we faced was putting the lowlink information into a coherent set of strongly connected components. However, this was resolved
	by using another vector to group together components that share the same root, adding the root if it wasn’t included, then 
	pushing those vectors into the return vector. The runtime for this algorithm was O(V+E).
	
	The most exciting discovery that we made in this project was through the implementation of Tarjan’s strongest component
	algorithm. This algorithm finds loop nests, which is how compilers similarly identify loop nests to optimize code.
