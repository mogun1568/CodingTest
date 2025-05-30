#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, c, a, ans = 0;
    
    cin >> N;
    while(N--) {
        cin >> c;
        pq.push(c);
    }

    while (pq.size() > 1) {
        a = pq.top();
        pq.pop();
        a += pq.top();
        pq.pop();

        ans += a;
        pq.push(a);
    }

    cout << ans;
    
    return 0;
}