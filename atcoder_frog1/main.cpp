#include <iostream>
#include <vector>
#include <cmath> 
#include <cstring>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v;
	vector<int> dp(n,1000);
	
	
	for(int i = 0 ;i  < n; i++){
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	dp[0] = 0;
	
	for(int i = 1; i < n; i++){
		for(int j = i-2; j < i; j++){
			if(j >= 0){
				int val = abs(v[i]-v[j]) + dp[j];
				dp[i] = min(dp[i], val);
			}
		}
	}
	
	for(int i =0 ; i < n; i ++) cout << dp[i]<< " "; cout << "\n";
	
	cout << dp[n-1];
	return 0;
}