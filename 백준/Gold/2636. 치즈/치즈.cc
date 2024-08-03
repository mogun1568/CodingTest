#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, hour, piece;
int board[100][100];
bool visited[100][100];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int Bfs() {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.push({0, 0});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (visited[nr][nc])
                continue;

            visited[nr][nc] = true;
            if (board[nr][nc] == 1) {
                board[nr][nc] = 0;
                cnt++;
            } 
            else
                q.push({nr, nc});
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    while (1) {
        int cnt = Bfs();
        if (cnt == 0)
            break;
        
        hour++;
        piece = cnt;
    }

    cout << hour << "\n" << piece;
    
    return 0;
}