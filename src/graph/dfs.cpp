#include "graph.h"

std::vector<int> Graph::DFS() {
  std::vector<int> result;

  std::stack<int> _stack;
  std::vector<bool> _visited(graph_.size(), false);

  int push_index = 0;
  _stack.push(push_index);
  
  while (!_stack.empty()) {
    push_index = _stack.top();
    _stack.pop();
    if (!_visited[push_index]) {
      result.push_back(push_index);
      _visited[push_index] = true;
      for (size_t i=0; i < graph_[push_index].size(); i++) {
        _stack.push(graph_[push_index][i].first);
      }
    }
  }
  return result;
}