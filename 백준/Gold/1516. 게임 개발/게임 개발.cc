#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int build[501];
vector<int> before[501];
int inDegree[501];
int dp[501];

void Bfs() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            dp[i] = build[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < before[cur].size(); i++) {
            int next = before[cur][i];
            
            inDegree[next]--;
            dp[next] = max(dp[next], dp[cur] + build[next]);

            if (inDegree[next] == 0)
                q.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    int b;
    for (int i = 1; i <= N; i++) {
        cin >> build[i];
        while (1) {
            cin >> b;
            if (b == -1)
                break;
            
            before[b].push_back(i);
            inDegree[i]++;
        }
    }

    Bfs();

    for (int i = 1; i <= N; i++) {
        cout << dp[i] << "\n";
    }
    
    return 0;
}