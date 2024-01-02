#include <iostream>
#include <queue>

using namespace std;

int R, C, sheepResult, wolfResult;
char garden[250][250];
bool visit[250][250];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(int r, int c) {
    int sheep = 0, wolf = 0;
    queue<pair<int, int>> q;
    visit[r][c] = true;
    q.push({r, c});

    if (garden[r][c] == 'o') {
        sheep++;
    } else if (garden[r][c] == 'v') {
        wolf++;
    }

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                continue;
            }

            if (garden[nr][nc] == '#' || visit[nr][nc]) {
                continue;
            }

            if (garden[nr][nc] == 'o') {
                sheep++;
            } else if (garden[nr][nc] == 'v') {
                wolf++;
            }

            visit[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    if (sheep > wolf) {
        sheepResult += sheep;
    } else {
        wolfResult += wolf;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    string s;
    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++) {
            garden[i][j] = s[j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (garden[i][j] == '#' || visit[i][j]) {
                continue;
            }

            bfs(i, j);
        }
    }

    cout << sheepResult << " " << wolfResult;
    
    return 0;
}