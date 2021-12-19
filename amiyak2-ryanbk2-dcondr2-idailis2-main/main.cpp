#include <string>

#include "src/graph/graph.h"
#include "src/ParseToVector/VectorTuple.h"

using std::string;

int main() {
	vector<std::tuple<int, int, int, int>> vec;
	string textFile = "data/graph.txt";
	vec = createMap(getVector(textFile));
	Graph g(vec);
	
	cout << endl;
	cout << "All of the edges:" << endl;
	g.print();
	// cout << endl;

	cout << "DFS Traversal:" << endl;
	vector<int> traversal = g.DFS();
	for (size_t i=0; i < traversal.size(); i++) {
		cout << traversal[i] << " ";
	}
	cout << endl;
	cout << endl;

	cout << "Strongly Connected Components:" << endl;
	vector<vector<int>> loopNests = g.getLoopNest();
	for (size_t i = 0; i < loopNests.size(); i++) {
		for (size_t j = 0; j < loopNests[i].size(); j++) {
			cout << loopNests[i][j] << " --> ";
		}
		cout << loopNests[i][0] << endl;
	}
	cout << endl;

	vector<int> distFromSource = g.getShortestPath();
	cout << "Shortest Distance from Node 0 to each other node:" << endl;
	for (size_t i=0; i < distFromSource.size(); i++) {
		cout << "0 --> " << i << ": " << distFromSource[i] << endl;
	}

	return 0;
}


