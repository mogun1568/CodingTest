#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, card;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++) {
        cin >> card;
        pq.push(card);
    }

    long long sum;
    for (int i = 0; i < m; i++) {
        sum = pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();

        pq.push(sum);
        pq.push(sum);
    }

    sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    cout << sum;
    
    return 0;
}