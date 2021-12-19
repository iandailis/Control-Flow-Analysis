#pragma once

#include <vector>
#include <stack>
#include <tuple>
#include <utility>
#include <iostream>
#include <stack>

using std::stack;

using std::cout;
using std::endl;

using std::vector;
using std::tuple;
using std::pair;
using std::get;
using std::make_pair;

class Graph {
	public:
		/**
		 * @param input tuple of nodes represented by the index, weight, edge1, edge2
		 * builds the graph_ variable for use in DFS which is a 2d vector of pairs
		 * with the first being the destination and second = weight. 
		*/
		Graph(vector<tuple<int, int, int, int>>);
	
		vector<int> getShortestPath();
		vector<vector<int>> getLoopNest();
		void print();
		std::vector<int> DFS();
	private:
		/**
		 * A graph represented by an adjacency list
		 * Graph[i][j].first = destination, Graph[i][j].second = weight
		*/
		vector<vector<pair<int, int>>> graph_;
		void strongconnect(vector<int> & index, vector<int> & lowlink, vector<bool> & onStack, int & master_index, stack<int> & s, int v);
};
