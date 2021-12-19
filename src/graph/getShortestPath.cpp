#include <climits>
#include <queue>

#include "graph.h"

using std::priority_queue;

vector<int> Graph::getShortestPath() {

	priority_queue<pair<int, int>> q;

	vector<int> dist;
	dist.resize(graph_.size());
	
	vector<int> prev;
	prev.resize(graph_.size());

	vector<bool> visited;
	visited.resize(graph_.size());

	size_t i;
	dist[0] = 0;
	prev[0] = -1;
	q.push(make_pair(dist[0] * -1, 0));
	for (i=1; i < graph_.size(); i++) {
		dist[i] = INT_MAX;
		prev[i] = -1;
		q.push(make_pair(dist[i] * -1, i));
	}
	
	while (q.size()) {
		int u = q.top().second;
		q.pop();
		for (size_t i=0; i < graph_[u].size(); i++) {
			int alt = dist[u] + graph_[u][i].second;
			if (alt < dist[graph_[u][i].first]) {
				dist[graph_[u][i].first] = alt;
				prev[graph_[u][i].first] = u;
				q.push(make_pair(-1 * alt, graph_[u][i].first));
			}
		}
	}

	return dist;

}
