#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<long long, vector<long long>, greater<long long>> pq;
long long answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int c, len;
    long long a;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> c;
        pq.push(c);
    }

    while (pq.size() > 1) {
        a = pq.top();
        pq.pop();
        a += pq.top();
        pq.pop();

        answer += a;
        pq.push(a);
    }

    cout << answer;
    
    return 0;
}