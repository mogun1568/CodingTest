#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1000][1000];
bool visit[1000][1000];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(int r, int c) {
    queue<pair<int, int>> q;
    visit[r][c] = true;
    q.push({r, c});

    while (!q.empty())  {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }

            if (map[nr][nc] == -1 && !visit[nr][nc]) {
                map[nr][nc] = map[r][c] + 1;    
                visit[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int r, c;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 2) {
                r = i;
                c = j;
                map[i][j] = 0;
            }

            map[i][j] *= -1;
        }
    }

    bfs(r, c);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}