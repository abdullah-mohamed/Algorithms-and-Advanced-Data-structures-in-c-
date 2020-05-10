#include <iostream>
#include <vector>
using namespace std;

int main(){
	int nodes; cin >> nodes;
	vector<vector<int>> A(nodes, vector<int>(nodes, -1));
	
	for(int i = 0; i < nodes; i++)
		for(int j =0; j < nodes; j++){
			int tmp; cin >> tmp;
			A[i][j] = tmp;
		}
		
	// you need to copy the array to an answer array if you need orignal array
	
		
	for(int i = 0; i < nodes; i++){						// determines the skipped node (i+1)
		for(int j = 0 ; j < nodes; j++){				// determines the nodes we are trying to modify now through the skipped node
			if(j == i) continue;						// The skipped node 
			for(int k = 0 ; k < nodes; k++){			// goes all other nodes except the skipped and the current node
				if(k == i || k == j) continue;
				// intermediate node is "i"  --> [2,3] > [2,1] + [1,3]
				if(A[j][k] > A[j][i] + A[i][k]) A[j][k] = A[j][i] + A[i][k];
			}
		}
	}
	
	for(auto &x: A){
		for(int j: x) cout << j << " ";
		cout << "\n";
	}
	return 0;
}