#include <iostream>
#include <queue>
using namespace std;
#define MAX 100000

bool visited[MAX];

int BFS(int n, int k) {
    queue<pair<int, int>> q;
    visited[n] = true;
    q.push({n, 0});

    while (!q.empty()) {
        int c = q.front().first;
        int t = q.front().second;
        q.pop();

        if (c == k)
            return t;

        if (c - 1 >= 0 && !visited[c - 1]) {
            visited[c - 1] = true;
            q.push({c - 1, t + 1});
        }
        if (c + 1 <= MAX && !visited[c + 1]) {
            visited[c + 1] = true;
            q.push({c + 1, t + 1});
        }
        if (c * 2 <= MAX && !visited[c * 2]) {
            visited[c * 2] = true;
            q.push({c * 2, t + 1});
        }
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