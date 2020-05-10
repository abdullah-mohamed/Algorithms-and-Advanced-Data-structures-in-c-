#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<vector<int>> items {{60, 10}, {100, 20}, {120, 30}};
	int cap = 50, ans{0};
	
	vector<pair<double, int>> ptw{};
	for(int i = 0; i < items.size(); i++) 
		ptw.push_back(make_pair((double)items[i][0]/items[i][1], i));
	
	for(auto x: ptw) cout << x.first << " " << x.second << "\n";
	sort(ptw.begin(), ptw.end());
	for(auto x: ptw) cout << x.first << " " << x.second << "\n";
	
	for(int i = ptw.size()-1; i > -1; i--){
		if(items[ptw[i].second][1] <= cap){
			cap -= items[ptw[i].second][1];
			ans += items[ptw[i].second][0];
		}else{
			ans += cap * (items[ptw[i].second][0]/items[ptw[i].second][1]);
			break;
		}
	}
	
	cout << ans << "\n";
	return 0;
}