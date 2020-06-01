#include <iostream>
#include <cstring>
#include <vector>

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
	public:

		Node(char*, int, Node*);
		char* getVal();
		int getWeight();
		Node* getSecond();
		vector<Node*> getEdges();
		void addEdge(int, Node*);
		void removeEdge(char*);
		~Node();
	private:
		int weight;
		vector<Node*> edges;
		Node* second;
		char* val;	
};
#endif
