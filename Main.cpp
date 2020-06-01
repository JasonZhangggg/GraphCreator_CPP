#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <iterator>
#include "Node.h"
using namespace std;

void addEdge(vector<Node*>&, char*, char*, int);
void print(vector<Node*>);
void removeVertex(vector<Node*>&, char*);
int main(){
	vector<Node*> vecs;
	while(true){
		char input[80];
		cout<<"Input ADDVERTEX to add a vertex, ADDEDGE to add a edge, PRINT to print, DELETE to delete a vertex, and QUIT to exit the program."<<endl;
		cin.getline(input, sizeof(input));
		for(int i = 0; i<sizeof(input); i++){
			input[i] = toupper(input[i]);
		}
		if(strcmp(input, "ADDVERTEX") == 0){
			char* val = new char();
			cout<<"What value would you like to add?"<<endl;
			cin.getline(val, sizeof(val));
			vecs.push_back(new Node(val, 0, NULL));
		}
		else if(strcmp(input, "ADDEDGE") == 0){
			char* first = new char();
			char* second = new char();
			cout<<"What is the first vertex?"<<endl;
			cin.getline(first, sizeof(first));
			cout<<"What is the second vertex?"<<endl;
			cin.getline(second, sizeof(second));
			int weight;
			cout<<"What is the weight of this edge?"<<endl;
			cin>>weight;
			cin.ignore();
			addEdge(vecs, first, second, weight);
		}
		else if(strcmp(input, "PRINT") == 0){
			print(vecs);
		}
		else if(strcmp(input , "DELETE") == 0){
			char* val = new char();
			cout<<"What is the value you want to delete?"<<endl;
			cin.getline(val, sizeof(val));
			removeVertex(vecs, val);
		}
		else if(strcmp(input, "QUIT") == 0){
			break;
		}
	}
	return 0;
}
void addEdge(vector<Node*>&vecs, char* first, char* second, int weight){
	vector<Node*>::iterator it;
	vector<Node*>::iterator firstLoc;
	vector<Node*>::iterator secondLoc;
	int found = 0;
	for(it = vecs.begin(); it != vecs.end(); ++it){
		if(strcmp((*it)->getVal(), first) == 0){
			firstLoc = it;
			found++;
		}
		else if(strcmp((*it)->getVal(), second) == 0){
			secondLoc = it;
			found++;
		}
	}
	if(found != 2){
		cout<<"One of the vertexes was not found"<<endl;
	}
	else{
		(*firstLoc)->addEdge(weight, (*secondLoc));
	}
}
void removeVertex(vector<Node*> &vecs, char* val){
	vector<Node*>::iterator it;
	for(it = vecs.begin(); it != vecs.end(); ++it){
		if(strcmp((*it)->getVal(), val) == 0){
			delete (*it);
			vecs.erase(it);
			--it;
		}
		else{
			(*it)->removeEdge(val);
		}
	}
}
void print(vector<Node*>vecs){
	vector<Node*>::iterator it;
	for(it = vecs.begin(); it != vecs.end(); ++it){
		vector<Node*> edges = (*it)->getEdges();
		vector<Node*>::iterator it2;
		cout<<"The vertex: "<<(*it)->getVal()<<" is connected to:";
		for(it2 = edges.begin(); it2 != edges.end(); ++it2){
			cout<<"   "<<(*it2)->getSecond()->getVal()<<" with weight:"<<(*it2)->getWeight();
		}
		cout<<endl;
	}
}

