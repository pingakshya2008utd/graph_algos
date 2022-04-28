#include "graph.h"
#include "node.h"

using namespace std;

graph::graph(int v) :V(v) {

}

void  graph::add_edge(node* s, node* d, int weight) {
	adj_list[s].push_back({weight,d });
	node_set.insert(s);
	node_set.insert(d);

	// adj_list[d].push_back(s);

}

void graph::dfs(node* s) {
	s->visited = true;
	cout << s->val << " ";

	if (adj_list.find(s) != adj_list.end()) {
		list<pair<int, node*>> node_list = adj_list.find(s)->second;
		for (auto curr_node : node_list) {
			node* node_v = curr_node.second;
			if (!node_v->visited)
				dfs(node_v);
		}
	}
}

void graph::bfs(node* s) {
	queue <node*> q;
	s->visited = true;
	q.push(s);

	while (!q.empty()) {
		node* top_node = q.front();

		cout << top_node->val << " ";
		q.pop();

		if (adj_list.find(top_node) != adj_list.end()) {
			list<pair<int, node*>> node_list = adj_list.find(top_node)->second;
			for (auto curr_node : node_list) {
				if (!curr_node.second->visited) {
					curr_node.second->visited = true;
					q.push(curr_node.second);
				}
			}
		}

	}
}


void graph::find_topo_sort_h(node* s, stack<node*>& topo_stack) {
	s->visited = true;

	if (adj_list.find(s) != adj_list.end())
	{
		list<pair<int,node*>> node_list = adj_list.find(s)->second;
		for (auto curr_node : node_list) {

			if (!curr_node.second->visited) {
				find_topo_sort_h(curr_node.second, topo_stack);

			}
		}
	}

	topo_stack.push(s);

}

void graph::topo_sort() {

	stack<node*> topo_stack;
	for (auto &curr_node : node_set) {
		if (!curr_node->visited) {
			find_topo_sort_h(curr_node, topo_stack);
		}
	}
	while (!topo_stack.empty()) {
		topo_sort_vec.push_back(topo_stack.top());
		cout << topo_stack.top()->val << " ";
		topo_stack.pop();
	}

}

void graph::clear_toposort() {
	topo_sort_vec.clear();
}

bool graph::detect_cycle_h(node *s, vector<node*>& curr_stack) {

	if ( find(curr_stack.begin(), curr_stack.end(), s) != curr_stack.end() )  //cycle present
		return false;
	else {
		curr_stack.push_back(s);
		s->visited = true;
		if (adj_list.find(s) != adj_list.end())
		{
			list<pair<int, node*>> node_list = adj_list.find(s)->second;
			for (auto curr_node : node_list) {

				if (!detect_cycle_h(curr_node.second, curr_stack)) {
					return false;

				}
			}


		}
		curr_stack.erase(std::remove(curr_stack.begin(), curr_stack.end(), s), curr_stack.end());
	}

	return true; //cycle does not presnet

}


bool graph::detect_cycle() {
	vector<node*> curr_stack;

	auto it = node_set.begin();
	return detect_cycle_h(*it, curr_stack);


}

void graph::find_longest_path(node* s) {
	unordered_map<node*, int> dist_map;

	for (auto &curr_node : node_set) {
		if (curr_node != s) {
			dist_map.emplace(curr_node, INT_MIN);
		}
		else {
			dist_map.emplace(curr_node, 0);
		}
	}

	stack<node*> topo_stack;
	for (auto &curr_node : node_set) {
		if (!curr_node->visited) {
			find_topo_sort_h(curr_node, topo_stack);
		}
	}

	while (!topo_stack.empty()) {
		node* curr_node = topo_stack.top();
		topo_stack.pop();
		list<pair<int, node*>> node_list = adj_list.find(curr_node)->second;
		if (dist_map[curr_node] != INT_MIN) {
			int prev_dist = dist_map[curr_node];
			for (auto curr_node_pair: node_list){
				int curr_dist = curr_node_pair.first;
				node* node_val = curr_node_pair.second;

				int updated_dist = max(curr_dist + prev_dist, curr_dist);
				dist_map.emplace(curr_node, updated_dist);
			}
		}
	}

	for (auto & m : dist_map) {
		cout << m.first << "->" << m.second << endl;
	}


}

graph::~graph() {
	node_set.clear();
	topo_sort_vec.clear();
	adj_list.clear();
	longest_path_vec.clear();
	cout << "destructor called" << endl;


}


