#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define INF 1000000

int R, C;
char maze[1001][1001];
int fire[1001][1001];
int visited[1001][1001];
pair<int, int> J;
queue<pair<int, int>> fireQ;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void fireBfs() {
    while (!fireQ.empty()) {
        int cr = fireQ.front().first;
        int cc = fireQ.front().second;
        fireQ.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 1|| nr > R || nc < 1 || nc > C)
                continue;

            if (maze[nr][nc] == '#' || fire[nr][nc] <= fire[cr][cc] + 1)
                continue;

            fire[nr][nc] = fire[cr][cc] + 1;
            fireQ.push({nr, nc});
        }
    }
}

void Bfs() {
    queue<pair<int, int>> q;
    visited[J.first][J.second] = 1;
    q.push({J.first, J.second});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (cr == 1 || cr == R || cc == 1 || cc == C) {
            cout << visited[cr][cc];
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 1|| nr > R || nc < 1 || nc > C)
                continue;

            if (maze[nr][nc] == '#' || visited[nr][nc] != 0)
                continue;
            
            if (visited[cr][cc] >= fire[nr][nc])
                continue;

            visited[nr][nc] = visited[cr][cc] + 1;
            q.push({nr, nc});
        }
    }

    cout << "IMPOSSIBLE";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= C; j++) {
            maze[i][j] = s[j - 1];
            fire[i][j] = INF;

            if (maze[i][j] == 'J') {
                J.first = i;
                J.second = j;
            }
            else if (maze[i][j] == 'F') {
                fire[i][j] = 0;
                fireQ.push({i, j});
            }
        }
    }

    fireBfs();
    Bfs();  
    
    return 0;
}