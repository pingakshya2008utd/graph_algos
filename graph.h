#ifndef GRAPH_H
#define GRAPH_H

#include<list>
#include <unordered_map>
#include<vector>
#include<iostream>
#include <queue>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include "node.h"



class graph {

	int V;
	unordered_map<node*, list<pair<int,node*>>> adj_list;
	unordered_set <node*> node_set;
	vector <node*> topo_sort_vec;
	vector <node*> longest_path_vec;
	void find_topo_sort_h(node* s, stack<node*>& topo_stack);
	bool detect_cycle_h(node *s, vector<node*>& curr_stack);
public:
	graph(int v);
	void add_edge(node* s, node* d, int weight);
	void dfs(node* s);
	void bfs(node* s);
	void topo_sort();
	void clear_toposort();
	bool detect_cycle();
	void find_longest_path(node* s);
	/*
	void find_longest_path(node* s);
	void clear_longest_path();
	*/
	~graph();
	
};

#endif

