#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y){
	int tmp = x;
	x = y;
	y = tmp;
}

int partition(vector<int> &v, int l, int r){
	int pivot = v[l];
	int i = l, j = r;
	while(i<j){
		while(v[i] <= pivot && i < r) i++; 	// do{i++;}
		while(v[j] > pivot && j > l) j--;     // do{j--;}
		if(i < j) swap(v[i], v[j]);
	}
	swap(v[l], v[j]);					// i is always greater than j here !!
	return j;
}

int partition(vector<int> &v, int l, int r){
	int pivot = v[l];
	int i = l, j = r;
	while(i < j){
		do{
			i++;
		}while(v[i] <= pivot && i < r);
		
		do{
			j--;
		}while(v[j] > pivot && j > l);
		
		if(i<j){
			int tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
		}
	}
	int tmp = v[j];
	v[j] = v[l];
	v[l] = tmp;
	return j;
}

void quickSort(vector<int> &v, int l, int r){
	if(l == r) return;
	
	int j = partition(v, l, r);
	quickSort(v, l, j);
	quickSort(v, j+1, r);
}

int main(){
	vector<int> v{9,7,8,1,4,10,0};
	v.push_back(24000000);			// max_int
	quickSort(v, 0, v.size()-1);
	v.pop_back();
	for(int i: v) cout << i << " ";
	return 0;
}