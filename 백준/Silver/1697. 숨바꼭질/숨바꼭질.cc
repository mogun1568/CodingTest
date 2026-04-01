#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001

bool visited[MAX];
queue<pair<int, int>> q;

void TryVisit(int next, int sec) {
    if (next < 0 || next >= MAX)
        return;
    
    if (!visited[next]) {
        visited[next] = true;
        q.push({next, sec + 1});
    }
}

int BFS(int n, int k) {
    visited[n] = true;
    q.push({n, 0});

    while (!q.empty()) {
        int cur = q.front().first;
        int sec = q.front().second;
        q.pop();

        if (cur == k)
            return sec;

        TryVisit(cur - 1, sec);
        TryVisit(cur + 1, sec);
        TryVisit(2 * cur, sec);
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    cout << BFS(N, K);
    
    return 0;
}