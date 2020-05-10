#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int l, int r){
	int mid = ((r+l)/2)+1;
	for(int i = mid, j = l; i <= r && j < mid; i++){
		while(v[j] < v[i]) j++;
		//if(j < mid){
		if(i <= r){
			int el = v[i];
			for(int k = i; k > j; k--)	v[k] = v[k-1];
			v[j] = el;
		}
	}
}

void mergeSort(vector<int> &v, int l, int r){
	if(r == l) return;
	
	int mid = (l + r)/2;
	mergeSort(v, l, mid);
	mergeSort(v, mid+1, r);
	merge(v, l, r);
}

int main(){
	vector<int> c {6,0,4,9,-1, -10};
	mergeSort(c, 0, c.size()-1);
	
	for(int i : c) cout <<i << " ";
	return 0;
}