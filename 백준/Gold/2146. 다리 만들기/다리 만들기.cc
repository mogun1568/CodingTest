#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, answer = 10000;
int map[100][100];
int visited[100][100];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void MapSetting(int r, int c, int mapN) {
    queue<pair<int, int>> q;
    visited[r][c] = 1;
    map[r][c] = mapN;
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

            if (map[nr][nc] == 0 || visited[nr][nc] == 1)
                continue;

            visited[nr][nc] = 1;
            map[nr][nc] = mapN;
            q.push({nr, nc});
        }
    }
}

void CheckBridge(int r, int c, int mapN) {
    queue<pair<int, int>> q;
    visited[r][c] = 0;
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

            if (map[nr][nc] == mapN)
                continue;
            else if (map[nr][nc] != 0) {
                answer = min(answer, visited[cr][cc]);
                return;
            }

            if (visited[cr][cc] + 1 >= visited[nr][nc])
                continue;


            visited[nr][nc] = visited[cr][cc] + 1;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int mapN = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0 || visited[i][j] == 1)
                continue;

            MapSetting(i, j, mapN++);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 10000;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0)
                continue;

            CheckBridge(i, j, map[i][j]);
        }
    }

    cout << answer;

    return 0;
}