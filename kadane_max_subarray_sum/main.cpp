#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySum(const vector<int> &v){
	int maxEndHere = 0, maxSoFar = 0;
	for(int i: v){
		maxEndHere += i;
		if(maxEndHere < 0) maxEndHere = 0;
		if(maxEndHere > maxSoFar) maxSoFar = maxEndHere;
	}
	return maxSoFar;
}
int main(){
	vector<int> v{-2, -3, 4, -1, -2, 1, 5, -3};
	cout << maxSubarraySum(v);
	return 0;
}