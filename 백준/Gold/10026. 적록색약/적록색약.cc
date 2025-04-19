#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int N;
char area[100][100];
bool visited[100][100];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void BFS(int r, int c) {
    char cur = area[r][c];
    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;

            if (visited[nr][nc] || area[nr][nc] != cur)
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

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++)
            area[i][j] = s[j];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j])
                continue;

            cnt++;
            BFS(i, j);
        }
    }
    cout << cnt << "\n";
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (area[i][j] == 'R')
                area[i][j] = 'G';
        }
    }

    cnt = 0;
    memset(visited, false, sizeof(visited));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j])
                continue;

            cnt++;
            BFS(i, j);
        }
    }
    cout << cnt << "\n";
    
    return 0;
}