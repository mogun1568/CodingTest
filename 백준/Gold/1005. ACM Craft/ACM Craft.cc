#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, K, W;
int D[1001];
vector<int> v[1001];
int preOrder[1001];
int dp[1001];

void Init() {
    for (int i = 1; i <= N; i++) {
        v[i].clear();
        preOrder[i] = 0;
        dp[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> D[i];
            dp[i] = D[i];
        }
        
        int x, y;
        while (K--) {
            cin >> x >> y;

            v[x].push_back(y);
            preOrder[y]++;
        }
        cin >> W;

        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if (preOrder[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
 
            for (int i = 0; i < v[cur].size(); i++) {
                int next = v[cur][i];
                
                dp[next] = max(dp[next], dp[cur] + D[next]);
                preOrder[next]--;
 
                if (preOrder[next] == 0) {
                    q.push(next);
                }
            }
        }

        cout << dp[W] << "\n";

        Init();
    }
    
    return 0;
}