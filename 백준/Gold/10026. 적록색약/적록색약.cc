#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int N;
string RGB[101];
bool visited[101][101];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void BFS(int r, int c) {
    char color = RGB[r][c];
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

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;

            if (RGB[nr][nc] != color)
                continue;

            if (visited[nr][nc])
                continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> RGB[i];

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                cnt++;
                BFS(i, j);
            }
        }
    }

    cout << cnt << " ";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (RGB[i][j] == 'G')
                RGB[i][j] = 'R';
        }
    }
    memset(visited, false, sizeof(visited));
    
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                cnt++;
                BFS(i, j);
            }
        }
    }

    cout << cnt;
    
    return 0;
}