#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	vector<int> profits{35, 30, 25, 20, 15, 12, 5}, deadLines{3, 4, 4, 2, 3, 1, 2};
	vector<pair<double, int>> sProfits;						// sorted profits
	
	// sort profits
	for(int i = 0; i < profits.size(); i++)
		sProfits.push_back({profits[i], i});
	sort(sProfits.begin(), sProfits.end());
	
	int maxJobs = *max_element(deadLines.begin(), deadLines.end());
	
	// answer
	vector<int> ans(maxJobs, -1); 
	
	// loop over all sorted elements and try to include them
	for(int  j = sProfits.size() - 1; j > -1 ; j--){
		auto job = sProfits[j];
		int dueTime = deadLines[job.second];
		
		for(int k = dueTime-1; k >= 0; k--){
			if(ans[k] == -1) {
				ans[k] = job.second; break;
			}
		}
	}
	
	int sol{0};
	for(int i: ans)
		if(i != -1) sol += profits[i];
	
	cout << sol << "\n";
	return 0;
}