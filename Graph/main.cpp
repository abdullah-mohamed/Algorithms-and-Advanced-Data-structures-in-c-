#include <iostream>

int N = 100;

// adjacency matrix
bool adjMatBool[N][N];
int adjMat[N][N];

vector<int> adjMatAll [N][N];		// keep all edges for a given pair of nodes

map< pair <int, int>, int> adjMatMap;	// sparse graph: imagine 100000 nodes, 50000 edges

// adjacency list
vector< vector<int> > adjListBool;
vector< vector< pair<int, int> > > adjList; 

int main(){
	
	return 0;
}