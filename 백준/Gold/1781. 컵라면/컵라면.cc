#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 200000;

pair<int, int> question[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> question[i].first >> question[i].second;
    
    sort(question, question + N);

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        pq.push(question[i].second);

        if (pq.size() > question[i].first)
            pq.pop();
    }

    long long ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;
    
    return 0;
}