#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, answer;
int institute[8][8];
bool visited[8][8];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int Bfs(int r, int c) {
    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});
    int cnt = 0;
    bool checkVirus = false;

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        cnt++;
        if (institute[cr][cc] == 2)
            //cout << cr << " " << cc << "\n";
            checkVirus = true;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (institute[nr][nc] == 1)
                continue;
            
            if (visited[nr][nc])
                continue;
            
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    if (checkVirus) 
        cnt = 0;
    
    return cnt;
}

int FindZero() {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (institute[i][j] == 1) 
                continue;

            if (visited[i][j])
                continue;

            cnt += Bfs(i, j);
        }
    }

    return cnt;
}

void Dfs(int cnt) {
    if (cnt == 3) {
        answer = max(answer, FindZero());
        return;
    } 
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (institute[i][j] == 0) {
                institute[i][j] = 1;
                Dfs(cnt + 1);
                institute[i][j] = 0;
            }
        }
    } 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> institute[i][j];
        }
    }

    Dfs(0);

    cout << answer;
    
    return 0;
}