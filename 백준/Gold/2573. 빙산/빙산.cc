#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int iceberg[300][300];
bool visited[300][300];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void BFS(int r, int c) {
    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        int zero = 0;
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (visited[nr][nc])
                continue;
            
            if (iceberg[nr][nc] == 0)
                zero++;
            else {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        iceberg[cr][cc] = max(0, iceberg[cr][cc] - zero);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> iceberg[i][j];
    }

    int ans = -1;
    bool check = false;
    
    while (1) {
        check = false;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (iceberg[i][j] == 0 || visited[i][j])
                    continue;

                if (check) {
                    cout << ans;
                    return 0;
                }

                ans++;
                check = true;
                BFS(i, j);
            }
        }

        if (!check)
            break;

        memset(visited, false, sizeof(visited));
    }

    cout << 0;

    return 0;
}