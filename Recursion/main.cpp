#include <iostream>
#include <algorithm>

using namespace std;

void triangle(int stars);		// prints a triangle of stars
int f3n_1(int n, int ans);		// prints the count of numbers in a 3 sequence
int f3n_1(int n);
void printNumber(int n);		// prints a number digit by digit
void printBits(int n);			// prints binary rep of a num

int grid[3][3] = {{5,1,2}, {6,7,8}, {1,8,9}};		int n = 3;
int gridmaxPath(int,int);

int main(){
	// triangle(9);
	// cout << f3n_1(22);
	cout << gridmaxPath(0,0);
	return 0;
}

void triangle(int stars){
	if(stars == 0) return;
	
	triangle(stars - 1);
	for(int i = 0 ; i < stars; i++){
		cout << "*";
	}
	cout << "\n";
	
}

int f3n_1(int n, int ans){
	if(n == 1) return ans + 1;
	
	if(n % 2 == 0) ans = f3n_1(n/2, ans + 1);
	else ans = f3n_1(3*n+1, ans + 1);
	
	return ans;
}

int f3n_1(int n){
	if(n == 1) return 1;
	
	if(n % 2 == 0) return 1 + f3n_1(n/2);
	return  1 + f3n_1(3*n+1);
}

void printNumber(int n){
	if(n){
		printNumber(n/10);
		cout << n % 10;
	}
}

void printBits(int n){
	if(n){
		printBits(n/2);
		cout << n%2;
	}
}

int gridmaxPath(int r, int c){
	if(r == n-1 && c == n-1) return max(grid[r][c] + grid[r][c-1], grid[r][c] + grid[r-1][c]);

	if(c > 0) grid[r][c] += grid[r][c-1];
	if(r > 0) grid[r][c] += grid[r-1][c];
	if(r < n && r != n-2)	return gridmaxPath(r+1, c);
	if(c < n) 	return gridmaxPath(r, c+1);
}

vector<int> vis(n, -1);
vis[0] = 0; vis[1] = 1;

int fibRec(int x){
	if(x <= 0) return 0;
	if(x <= 2) return 1;
	
	if(vis[x] != -1) return vis[x];
	vis[x] = fibRec(x-1) + fibRec(x-2)
	
	return vis[x];
}

int fibItr(int x){
	vector<int> fib{0,1};
	for(int i = 2; i <= x; i++){
		fib.push_back(fib[i-1]+fib[i-2]);
	}
	return fib[x];
}