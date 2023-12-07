#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int paper[500][500];
bool visit[500][500];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs(int r, int c) {
    int area = 1;
    queue<pair<int, int>> q;
    visit[r][c] = true;
    q.push({r, c});

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }

            if (paper[nr][nc] == 1 && !visit[nr][nc]) {
                visit[nr][nc] = true;
                q.push({nr, nc});
                area++;
            }
        }
    }

    return area; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    int cnt = 0, area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (paper[i][j] == 1 && !visit[i][j]) {
                area = max(area, bfs(i, j));
                cnt++;
            }
        }
    }

    cout << cnt << "\n" << area;

    return 0;
}