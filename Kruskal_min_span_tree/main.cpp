#include <iostream>
#include <vector>
#define OO 1000000000
using namespace std;

typedef struct edge{
	int from, to, w;
	edge(int from, int to, int w): from(from), to(to), w(w){};
	bool operator<(const struct edge &e) const{
		return w > e.w;
	}
} edge;

vector<edge> Kruskal(vector<vector<int>> adjList){
	int n = adjList.size();
	vector<edge> ans;
	vector<int> vis;
	
	// put all edges in q
	priority_queue<edge> q;
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < adjList[i].size(); j++){
			q.push(adjList[i][j]);
		}
	}
	
	while(ans.size() < n-1){
		edge e = q.top(); q.pop();
		if(vis[e.to] == 0 || vis[e.from] == 0){
			ans.push_back(e);
		}
	}
}

int main(){
	
	return 0;
}