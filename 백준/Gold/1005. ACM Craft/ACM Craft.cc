#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int D[1001];
int DP[1001];
vector<int> v[1001];
int inDegree[1001];

void Init() {
    for (int i = 1; i <= N; i++) {
        v[i].clear();
        inDegree[i] = 0;
    }
}

void BFS() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            DP[next] = max(DP[next], DP[cur] + D[next]);
            
            inDegree[next]--;
            if (inDegree[next] == 0)
                q.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T, K, X, Y, W;
    cin >> T;

    while (T--) {
        cin >> N >> K;

        for (int i = 1; i <= N; i++) {
            cin >> D[i];
            DP[i] = D[i];
        }
        
        while (K--) {
            cin >> X >> Y;
            v[X].push_back(Y);
            inDegree[Y]++;
        }

        cin >> W;
    
        BFS();

        cout << DP[W] << "\n";

        Init();
    }
    
    return 0;
}