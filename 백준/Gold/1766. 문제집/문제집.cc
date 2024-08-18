#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> question[32001];
int inDegree[32001];

void Bfs() {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0)
            pq.push(i);
    }

    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        cout << cur << " ";

        for (int i = 0; i < question[cur].size(); i++) {
            int next = question[cur][i];
            inDegree[next]--;

            if (inDegree[next] == 0)
                pq.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        question[a].push_back(b);
        inDegree[b]++;
    }

    Bfs();
    
    return 0;
}