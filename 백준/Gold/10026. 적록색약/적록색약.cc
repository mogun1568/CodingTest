#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int n;
char picture[100][100];
bool visited[100][100];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(int r, int c) {
    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                continue;
            }

            if (visited[nr][nc] || picture[nr][nc] != picture[cr][cc]) {
                continue;
            }

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            picture[i][j] = s[j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) {
                continue;
            }

            bfs(i, j);
            cnt++;
        }
    }

    cout << cnt << " ";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] == 'G') {
                picture[i][j] = 'R';
            }

        }
    }

    memset(visited, false, sizeof(visited));
    cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) {
                continue;
            }

            bfs(i, j);
            cnt++;
        }
    }

    cout << cnt;
    
    return 0;
}