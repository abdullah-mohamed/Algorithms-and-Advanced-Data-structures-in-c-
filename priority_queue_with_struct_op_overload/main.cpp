#include <iostream>
#include <queue> 
#include <algorithm>

struct Player{
    int ind;
    double val;
    
    Player(int i, double value): ind(i), val(value){}
    bool operator<(const Player& rhs)
    {
      return val < rhs.val;
    }
};

using namespace std;

int main(){
    int n, t1, t2, k;
    cin >> n >> t1 >> t2 >> k;
    priority_queue<Player> pq;
    
    for(int i = 0 ; i < n ; i++){
        int a, b; cin >> a >> b;
        double value = max(a * t1 * k + b * t2, b * t1 * k + a * t2);
        Player p = Player(i, value);
        pq.push(p);
    }
    
    while(!pq.empty()){
        Player x = pq.top();
        cout << (x.ind) + 1 << " " << x.val << "\n";
        pq.pop();
    }
    return 0;
}