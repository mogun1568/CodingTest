#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
bool aisle[101][101];
bool visit[101][101];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs(int r, int c) {
    int cnt = 0;
    queue<pair<int, int>> q;
    visit[r][c] = true;
    q.push({r, c});

    while (!q.empty()) {
        cnt++;
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 1 || nr > n || nc < 1 || nc > m) {
                continue;
            }

            if (aisle[nr][nc] && !visit[nr][nc]) {
                visit[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int k, r, c, result = 0;
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        aisle[r][c] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (aisle[i][j] && !visit[i][j]) {
                result = max(result, bfs(i, j));
            }
        }
    }

    cout << result;
    
    return 0;
}