#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

// 신뢰하는 자를 저장
vector<int> rel[10001];
bool visit[10001];

int bfs(int n) {
    int cnt = 0;
    queue<int> q;
    visit[n] = true;
    q.push(n);

    while (!q.empty()) {
        cnt++;
        int n = q.front();
        q.pop();

        for (int i = 0; i < rel[n].size(); i++) {
            if (!visit[rel[n][i]]) {
                visit[rel[n][i]] = true;
                q.push(rel[n][i]);
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        rel[b].push_back(a);
    }
    
    vector<int> result, tmp;
    int maxCnt = 0;
    for (int i = 1; i <= n; i++) {
        memset(visit, false, sizeof(visit));
        int cnt = bfs(i);
        if (cnt > maxCnt) {
            maxCnt = cnt;
            result = tmp;
            result.push_back(i);
        } else if (cnt == maxCnt) {
            result.push_back(i);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}