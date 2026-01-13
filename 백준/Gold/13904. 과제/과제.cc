#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> tasks[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> tasks[i].first >> tasks[i].second;
    
    sort(tasks, tasks + N);

    priority_queue<int, vector<int>, greater<int>> pq;
    for (const auto& task : tasks) {
        pq.push(task.second);

        if (pq.size() > task.first)
            pq.pop();
    }

    int point = 0;
    while (!pq.empty()) {
        point += pq.top();
        pq.pop();
    }

    cout << point;
    
    return 0;
}