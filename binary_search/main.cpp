#include <iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int x) 
{ 
	if(l > r) return -1;
	int m = (l+r)/2; // l + (r-l)/2
	if(arr[m] == x) return m;
	else if(arr[m] > x) return binarySearch(arr, l, m-1, x);
	else return binarySearch(arr, m+1, r, x);
} 

int main(){
	return 0;
}