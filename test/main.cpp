#include<bits/stdc++.h> 
using namespace std; 

bool isPerfectSquare(int num) {
        vector<unsigned long long int> v;            // sorted list, maybe use BS
        for(int i = 0; i <= 47000; i++){
            unsigned long long int x = i*i;
            v.push_back(x);
        }
        
        if(find(v.begin(), v.end(), num) != v.end()) return true;
        else return false;
    }

// Driver Code 
int main() 
{ 
	cout << isPerfectSquare(2147483647);
	return 0; 
} 
