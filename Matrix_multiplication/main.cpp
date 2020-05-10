#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixMul(vector<vector<int>> a, vector<vector<int>> b){
	vector<vector<int>> ans(a.size(), vector<int>(b[0].size(), 0));
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < b.size(); j++){
			int sum = 0;
			for(int k = 0; k < b.size(); k++){
				sum += a[i][k] * b[k][j]; 
			}
			ans[i][j] = sum;
		}
	}
	return ans;
}


void printMatrix(vector<vector<int>> mat){
	for(auto vec: mat){
		for(int i: vec) cout << i << " ";
		cout << "\n";
	}
}

int main(){
	vector<vector<int>> a = {{1, 5}, {7, 1}};
	vector<vector<int>> b = {{2, 3}, {4, 5}};
	vector<vector<int>> c = matrixMul(a,b);
	printMatrix(c);
	
	return 0;
}