#include <iostream>
#include <queue>

using namespace std;

int n, m, white, blue;
char battlefield[100][100];
bool visit[100][100];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(int r, int c, char color) {
    int cnt = 1;
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

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                continue;
            }

            if (battlefield[nr][nc] != color || visit[nr][nc]) {
                continue;
            }

            cnt++;
            visit[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    if (color == 'W') {
        white += cnt * cnt;
    } else {
        blue += cnt * cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    string s;
    for (int i = 0; i < m; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            battlefield[i][j] = s[j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j]) {
                continue;
            }

            bfs(i, j, battlefield[i][j]);
        }
    }

    cout << white << " " << blue;
    
    return 0;
}