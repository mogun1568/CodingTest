#include <iostream>
#include <queue>

using namespace std;

int visit[100001];

int n, k;

int bfs(int k) {
    queue<pair<int, int>> q;
    q.push({k, 0});
    visit[k] = true;

    while (1) {
        int t = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (t == n) {
            return cnt;
        }

        if (t % 2 == 0 && !visit[t / 2]) {
            visit[t / 2] = true;
            q.push({t / 2, cnt + 1});
        }

        if (t < 100000 && !visit[t + 1]) {
            visit[t + 1] = true;
            q.push({t + 1, cnt + 1});
        }
        
        if (t > 0 && !visit[t - 1]) {
            visit[t - 1] = true;
            q.push({t - 1, cnt + 1});
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;

    cout << bfs(k);
    
    return 0;
}