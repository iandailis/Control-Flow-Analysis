#include <algorithm>

#include "graph.h"

using std::min;

vector<vector<int>> Graph::getLoopNest()  {

	vector<vector<int>> ret;

	vector<int> index;
	index.resize(graph_.size());

	vector<int> lowlink;
	lowlink.resize(graph_.size());

	vector<bool> onStack;
	onStack.resize(graph_.size());

	size_t i;
	for (i=0; i < graph_.size(); i++) {
		index[i] = -1;
		lowlink[i] = -1;
		onStack[i] = false;
	}

	int master_index = 0;
	stack<int> s;

	int v;
	for (v=0; v < (int)graph_.size(); v++) {
		if (index[v] == -1) {
			strongconnect(index, lowlink, onStack, master_index, s, v);
		}
	}
	
	vector<vector<int>> processRet;
	processRet.resize(lowlink.size());

	for (i=0; i < lowlink.size(); i++) {
		processRet[lowlink[i]].push_back(i);
	}

	for (i=0; i < processRet.size(); i++) {
		if (processRet[i].size()) {
			if (processRet[i][0] != (int)i) {
				processRet[i].insert(processRet[i].begin(), lowlink[processRet[i][0]]);
			}
			ret.push_back(processRet[i]);
		}
	}
	return ret;
}

void Graph::strongconnect(vector<int> & index, vector<int> & lowlink, vector<bool> & onStack, int & master_index, stack<int> & s, int v){

	index[v] = master_index;
	lowlink[v] = master_index;
	master_index++;

	s.push(v);
	onStack[v] = true;

	size_t e;
	for (e=0; e < graph_[v].size(); e++) {
		int w = graph_[v][e].first;
		if (index[w] == -1) {
			strongconnect(index, lowlink, onStack, master_index, s, w);
			lowlink[v] = min(lowlink[v], lowlink[w]);
		} else if (onStack[w]) {
			lowlink[v] = min(lowlink[v], index[w]);
		}
	}
}
