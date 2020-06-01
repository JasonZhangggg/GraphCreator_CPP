#include <iostream>
#include <vector>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(char* newVal, int newWeight, Node* newSecond) {
	val = new char[sizeof(newVal)];
	strcpy(val, newVal);
	weight = newWeight;
	second = newSecond;
}
int Node:: getWeight(){
	return weight;
}
Node* Node:: getSecond(){
	return second;
}
char* Node:: getVal(){
	return val;
}
Node::~Node(){
	delete[] val;
}
vector<Node*> Node::getEdges(){
	return edges;
}
void Node:: addEdge(int newWeight, Node* newSecond){
	edges.push_back(new Node("", newWeight, newSecond));
}
void Node:: removeEdge(char* val){
	vector<Node*>::iterator it;
	for(it = edges.begin(); it != edges.end(); ++it){
		if(strcmp((*it)->getSecond()->getVal(), val) == 0){
			delete (*it);
			edges.erase(it);
			return;
		}
	}
}
