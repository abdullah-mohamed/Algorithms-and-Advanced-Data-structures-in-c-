#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calc(int v1, int v2, char op){
	int ans;
	switch(op){
		case '+':
			ans = v1 + v2;
			break;
		case '-':
			ans = v1 - v2;
			break;
		case '*':
			ans = v1 * v2;
			break;
		case '/':
			ans = v1 / v2;
			break;
		// default:
			// error
	}
	return ans;
}

int getNextOpIndex(vector<int> &vis){
	int idx = 0;
	while(vis[idx] != 0) idx++;
	return idx;
}

void paranth(vector<int> &v, vector<char> &op, int counter, vector<int> vis, int &val){		// vector<vector<int>> &m, vector<vector<int>> &k // TODO
	
	// base case
	if(counter == op.size()){					// we calculte the last operation then return
		// get last operation idx
		int idx = getNextOpIndex(vis);
		
		// do op, check for max
		val2 = clac( , , op[idx]);				// val of all before the sign and all after it
		val = max(val, val2);
		return;
	}
	
	vector<int> vis2{vis};						// This will be sent to rest of stacks
	for(int i = 0; i < counter; i++){
		// get last operation idx
		int idx = getNextOpIndex(vis);
		
		// do op, mark as visited
		
		vis[idx] = vis2[idx] = 1;
		
		// recurse for rest of operations
		paranth(v, op, counter-1, vis2, val);
		vis2[idx] = 0;				// negate the last done operation to allow other stacks to do it in the future
	}
}

int main(){
	string s; cin >> s;
	paranth(v, op, v.size(), vis, val, s);
	return 0;
}