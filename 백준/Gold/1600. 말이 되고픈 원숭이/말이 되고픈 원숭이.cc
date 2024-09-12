#include <iostream>
#include <queue>

using namespace std;

int K, W, H;
int board[201][201];
int visited[201][201][31];

int dr[12] = {-1, 1, 0, 0, 1, 2, 1, 2, -1, -2, -1, -2};
int dc[12] = {0, 0, -1, 1, 2, 1, -2, -1, 2, 1, -2, -1};

int Bfs() {
    queue<pair<pair<int, int>, int>> q;
    visited[1][1][K] = 1;
    q.push({{1, 1}, K});

    while (!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int ck = q.front().second;
        q.pop();

        if (cr == H && cc == W)
            return visited[cr][cc][ck] - 1;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 1 || nr > H || nc < 1 || nc > W)
                continue;

            if (board[nr][nc] == 1 || visited[nr][nc][ck] != 0)
                continue;

            visited[nr][nc][ck] = visited[cr][cc][ck] + 1;
            q.push({{nr, nc}, ck});
        }

        if (ck < 1)
            continue;

        for (int i = 4; i < 12; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            int nk = ck - 1;

            if (nr < 1 || nr > H || nc < 1 || nc > W)
                continue;

            if (board[nr][nc] == 1 || visited[nr][nc][nk] != 0)
                continue;

            visited[nr][nc][nk] = visited[cr][cc][ck] + 1;
            q.push({{nr, nc}, nk});
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> K >> W >> H;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> board[i][j];
        }
    }

    cout << Bfs();
    
    return 0;
}