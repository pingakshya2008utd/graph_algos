#include<iostream>
#include "graph.h"
#include "node.h"

int main() {
	graph* g=new graph(6);

	node* s0 = new node;
	node* s1 = new node;
	node* s2 = new node;
	node* s3 = new node;
	node* s4 = new node;
	node* s5 = new node;
	//node* s5= new node;

	s0->val = 0;
	s1->val = 1;
	s2->val = 2;
	s3->val = 3;
	s4->val = 4;
	s5->val = 5;

/*	g->add_edge(s0, s1, 5);
	g->add_edge(s1, s2, 3);
	g->add_edge(s2, s3, 6);
	g->add_edge(s0, s2, 6);
	*/
	g->add_edge(s1, s2, 2);
	g->add_edge(s2, s4, 4);
	g->add_edge(s2, s5, 2);
	g->add_edge(s2, s3, 7);
	g->add_edge(s3, s5, 1);
	g->add_edge(s3, s4, -1);
	g->add_edge(s4, s5, -2);
	
	g->topo_sort();
	/*
	if (g->detect_cycle()) cout << "cycle does not present"<<endl;
	else cout << "cycle present" << endl;

	g->topo_sort();
	g->dfs(s0);
	g->bfs(s0);
	*/
	delete g;
	//g->topo_sort();
	system("pause");
	return 0;

}
