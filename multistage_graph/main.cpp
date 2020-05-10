#include <iostream>
#include <vector>

#define INF 1e7
using namespace std;

int main(){
	cout << "Multistage graph problem.\nEnter number of nodes: ";
	int numOfNodes;	cin >> numOfNodes;								// num of nodes
	
	vector<vector<int>> con(numOfNodes);							// connections
	vector<vector<int>> weight(numOfNodes);							// weights
	vector<int> cost(numOfNodes), d(numOfNodes);					// cost and directions
	
	// Nodes and Edges entry
	for(int i = 0; i < numOfNodes; i++){
		cout << "Enter number of connections of node " << i+1 << " : ";
		int numOfConnections; cin >> numOfConnections;
		
		while(numOfConnections--){
			cout << "Enter a connection and its respective weight: ";
			int conn, w; cin >> conn >> w;
			con[i].push_back(conn);
			weight[i].push_back(w);
		}
	}
	
	// intial values
	cost[numOfNodes-1] = 0; d[numOfNodes-1] = numOfNodes;
	
	// make your table
	for(int i = numOfNodes-2; i >=0 ; i--){
		// loop for j from 0 to all connections of i
		int min = INF, n = -1;
		for(int j = 0; j < con[i].size(); j++){
			int endNode = con[i][j];
			int val = weight[i][j] + cost[endNode-1];
			if(val < min) min = val, n = endNode;
		}
		// get min of all connections and to which connection it was from
		cost[i] = min;
		d[i] = n;
	}
	
	/*for(int i: cost) cout << i << " "; 
	cout << "\n";
	for(int i: d) cout << i << " ";*/
	return 0;
}