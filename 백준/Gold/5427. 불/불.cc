#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

#define INF 1000000

int t, w, h;
char building[1000][1000];
int fire[1000][1000];
bool visited[1000][1000];
pair<int, int> sg;
queue<pair<int, int>> fireQ;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void FireBfs() {
    while (!fireQ.empty()) {
        int cr = fireQ.front().first;
        int cc = fireQ.front().second;
        fireQ.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= h || nc < 0 || nc >= w)
                continue;

            if (building[nr][nc] == '#' || fire[nr][nc] <= fire[cr][cc] + 1)
                continue;

            fire[nr][nc] = fire[cr][cc] + 1;
            fireQ.push({nr, nc});
        }
    }
}

void Bfs() {
    queue<pair<pair<int, int>, int>> q;
    visited[sg.first][sg.second] = true;
    q.push({{sg.first, sg.second}, 0});

    while (!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (cr == 0 || cr == h - 1 || cc == 0 || cc == w - 1) {
            cout << cnt + 1 << "\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= h || nc < 0 || nc >= w)
                continue;

            if (building[nr][nc] == '#' || visited[nr][nc])
                continue;

            if (cnt + 1 >= fire[nr][nc])
                continue;

            visited[nr][nc] = true;
            q.push({{nr, nc}, cnt + 1});
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < w; j++) {
                building[i][j] = s[j];
                fire[i][j] = INF;

                if (building[i][j] == '@') {
                    sg.first = i;
                    sg.second = j;
                }

                if (building[i][j] == '*') {
                    fire[i][j] = 0;
                    fireQ.push({i, j});
                }
            }
        }

        memset(visited, false, sizeof(visited));
        FireBfs();
        Bfs();
    }
    
    return 0;
}