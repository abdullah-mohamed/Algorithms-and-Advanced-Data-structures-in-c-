#include <iostream>
#include <vector>
#define OO 1000000000
using namespace std;

void pushEdges(const vector<vector<int>> &adjList, vector<int> &vis, priority_queue<edge> &q, int node) {
	for(int i = 0; i < adjList[node]; i++) {
		edge e = adjList[node][i];
		if(vis[e.to] == 0 || vis[e.form] == 0){
			q.push(e);
			vis[e.to] = vis[e.from] = 1;
		}
	}
}

typedef struct edge{
	int from, to, w;
	edge(int f, int t, int w): from(f), to(t), w(w){}
	bool operator<(const struct edge &e) const{
		return w > e.w;
	}
} edge;

vector<edge> prim(vector<vector<int>> adjList){
	int n = adjList.size();
	vector<edge> ans(n-1);						// answer
	vector<int> vis(n, 0);						// vistied nodes so far
	
	priority_queue<edge> q;
	// get min edge of all graph, put it in q		O(E)
	edge e; int minW = OO;
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < adjList[i].size(); j++){
			if(adjList[i][j].w < minW)
				e = adjList[i][j];
		}
	}
	ans.push_back(e);
	vis[e.to] = vis[e.from] = 1;
	
	// push all edges connected to e.to and e.from.   Note: we don't want to add the edge connecting them
	pushEdges(adjList, vis, q, e.to);
	pushEdges(adjList, vis, q, e.from);
	
	for(int i = 0 ; i < n-1; i++){
		edge e = q.top(); q.pop();						// // next min edge
		ans.push_back(e);
		vis[e.to] = 1;
		pushEdges(adjList, vis, q, e.to);
	}
	
	return ans;
}
int main(){
	std::cout << "Hello World!" << std::endl;
	return 0;
}