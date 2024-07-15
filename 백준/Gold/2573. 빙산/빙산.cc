#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, answer;
int sea[300][300];
bool visited[300][300];
int check;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void Iceberg(int r, int c) {
    int cnt = 0;
    
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;

        if (visited[nr][nc] || sea[nr][nc] != 0)
            continue;

        cnt++;
    }

    sea[r][c] = max(sea[r][c] - cnt, 0);
}

void Bfs(int r, int c) {
    check = 1;
    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        Iceberg(cr, cc);

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (visited[nr][nc] || sea[nr][nc] == 0)
                continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> sea[i][j];
        }
    }

    int cnt = 0;
    while (true) {
        check = 0;
        cnt = 0;
        memset(visited, false, sizeof(visited));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] || sea[i][j] == 0) {
                    cnt++;
                    continue;
                }     
    
                if (check == 1) {
                    check = 2;
                    break;
                }       
                    
                Bfs(i, j);
            }

            if (check == 2)
                break;
        }

        if (check == 2)
            break;
        
        if (cnt == N * M) {
            answer = 0;
            break;
        }

        answer++;
    }

    cout << answer;
    
    return 0;
}