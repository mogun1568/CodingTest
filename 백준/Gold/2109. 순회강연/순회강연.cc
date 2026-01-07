#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> lecture[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> lecture[i].second >> lecture[i].first;
    sort(lecture, lecture + N);

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        pq.push(lecture[i].second);

        if (pq.size() > lecture[i].first)
            pq.pop();
    }

    int cost = 0;
    while (!pq.empty()) {
        cost += pq.top();
        pq.pop();
    }

    cout << cost;
    
    return 0;
}