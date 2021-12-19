#include "graph.h"

Graph::Graph(vector<tuple<int, int, int, int>> input) {
	graph_.resize(input.size());
	size_t i;
	for (i=0; i < input.size(); i++) {
		if (get<2>(input[i]) != -1) {
			graph_[i].push_back(make_pair(get<2>(input[i]), get<1>(input[get<2>(input[i])])));
		}
		if (get<3>(input[i]) != -1) {
			graph_[i].push_back(make_pair(get<3>(input[i]), get<1>(input[get<3>(input[i])])));
		}
	}
}

void Graph::print() {
	size_t i, j;
	for (i=0; i < graph_.size(); i++) {
		for (j=0; j < graph_[i].size(); j++) {
			cout << i << "-->" << graph_[i][j].first << " weight: " << graph_[i][j].second << ". ";
		}
		cout << endl;
	}
}
