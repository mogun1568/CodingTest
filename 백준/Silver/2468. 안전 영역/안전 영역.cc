#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int area[100][100];
bool visit[100][100];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void bfs(int r, int c, int h) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visit[r][c] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                continue;
            }

            if (area[nr][nc] > h && !visit[nr][nc]) {
                q.push({nr, nc});
                visit[nr][nc] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int maxH = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> area[i][j];
            maxH = max(maxH, area[i][j]);
        }
    }

    int result = 0, cnt;
    for (int h = 0; h <= maxH; h++) {
        cnt = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (area[r][c] > h && !visit[r][c]) {
                    cnt++;
                    bfs(r, c, h);
                }
            }
        }

        result = max(result, cnt);

        memset(visit, false, sizeof(visit));
    }

    cout << result;

    return 0;
}