#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int N, K;
int point[MAX];
int dp[MAX];

void Bfs() {
    queue<int> q;
    dp[N] = 1;
    q.push(N);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (cur == K) {
            return;
        }

        for (int next : {cur - 1, cur + 1, cur * 2}) {
            if (next < 0 || next >= MAX)
                continue;

            if (point[next] == 0) {
                point[next] = point[cur] + 1;
                dp[next] = dp[cur];
                q.push(next);
            }
            else {
                if (point[cur] + 1 == point[next])
                    dp[next] += dp[cur];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;

    if (N == K) {
        cout << 0 << "\n" << 1;
        return 0;
    }

    Bfs();

    cout << point[K] << "\n" << dp[K];
    
    return 0;
}