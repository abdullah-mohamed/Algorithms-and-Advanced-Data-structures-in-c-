#include <iostream>
#include <vector>
#define OO 1000000000

using namespace std;

int Dijkstra1(vector<vector<int>> adjMat, int src, int dest = -1){
	int n = adjMat.size();
	vector<int> vis(n, 0), dist(n, OO), prev(n, -1);
	dist[src] = 0;
	
	while(true){
		// get min distance node and its index
		int val = OO, idx = -1;
		for(int i = 0; i < n; i++)
			if(!vis[i] && dist[i] < val) val = dist[i], idx = i;
		
		// go out if you can't find a node or you reached the destination
		if(idx == -1 || idx == dest) break;
		
		// relax if needed
		for(int i = 0; i < n; i++){
			if(dist[i] > (val = dist[idx] + adjMat[idx][i]))
				dist[i] = val, prev[i] = idx;
		}
		
		return dest == -1? -1: dist[dest];
	}
}

struct edge {
	int from, to, w;
	
	edge(int from, int to, int w): from(from), to(to), w(w){};
	
	bool operator<(const struct edge &e) const{
		return w > e.w;
	}
};

int Dijkstra2(vector<vector<edge>> adjList, int src, int dest = -1){
	int n = adjList.size();
	vector<int> dist(n, OO), prev(n, -1);
	dist[src] = 0;
	
	priority_queue<edge> q;
	q.push(edge(-1, src, 0));
	
	while(!q.empty()){
		edge e = q.top; q.pop();
		
		if(e.w > dist[e.to]) continue;
		
		prev[e.to] = e.from;
		
		for(int i = 0 ; i < adjList[e.to]; i++){
			edge ne = adjList[e.to][i];
			if(dist[ne.to] > dist[ne.from] + ne.w){
				ne.w = dist[ne.to] = dist[ne.from] + ne.w;
				q.push(ne);
			}
		}
	}
	return (dest == -1)? -1: dist[dest];
}

int main(){
	
	return 0;
}