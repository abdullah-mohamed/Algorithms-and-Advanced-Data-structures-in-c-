#include <iostream>
#include <vector>
#define OO 1000000000
using namespace std;

int calc(int v1, int v2, char op){
	int ans;
	switch(op){
		case '+':
			ans = v1 + v2;
			break;
		case '-':
			ans = v1 - v2;
			break;
		case '*':
			ans = v1 * v2;
			break;
		case '/':
			ans = v1 / v2;
			break;
		// default:
			// error
	}
	return ans;
}

int main(){
	// 5 - 8 + 7 * 4 - 8 + 9
	int n; cin >> n;
	vector<int> v(n);
	vector<char> op(n-1);
	vector<vector<int>> m(n, vector<int>(n, 0)), k2(n, vector<int>(n, 0));
	
	// integers i/p  // can't be zero
	for(int i = 0 ;i < n; i++){
		int tmp; cin >> tmp; 
		// if(tmp == 0) //error
		v[i] = tmp;
	}
	
	// char i/p
	string tmp; cin >> tmp; 
	for(int i = 0; i < tmp.length(); i++) op[i] = tmp[i];
	
	for(int i=0; i<v.size(); i++) m[i][i] = v[i];
	
	// calculate
	for(int i = 1; i < n; i++){						// difference between 2 elements at first 1, 2, 3
		for(int j = 0; j < n; j++){					// row
			for(int k = j+1; k < n; k++){			// col
				if(k-j == i){						// check if difference is applicable to reserve the precedence of calculations
					int max = -OO, idx;
					for(int l = j; l < k; l++){
						int val = calc(m[j][l], m[l+1][k], op[l]);
						// cout << i << " \t" << j << "\t " << k << "\t" << m[j][l] << "\t" << m[l+1][k] << "\t" << val << "\n";
						if(max < val){
							max = val;
							idx = l;
						}
					} 
					m[j][k] = max;
					k2[j][k] = idx;
				}
			}
		}
	}
	
	for(auto &x: m){
		for(int i: x) cout<< i << "   ";
		cout << "\n";
	}
	
	for(auto &x: k2){
		for(int i: x) cout<< i << " ";
		cout << "\n";
	}
		
	return 0;
}