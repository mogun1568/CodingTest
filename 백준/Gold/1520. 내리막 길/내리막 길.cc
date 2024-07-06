#include <iostream>

using namespace std;

int M, N;
int map[500][500];
int dp[500][500];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int Dfs(int r, int c) {
    if (r == M - 1 && c == N - 1)
        return 1;

    if (dp[r][c] != -1)
        return dp[r][c];

    dp[r][c] = 0;
    
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= M || nc < 0 || nc >= N)
            continue;

        if (map[nr][nc] >= map[r][c])
            continue;

        dp[r][c] += Dfs(nr, nc);
    }

    return dp[r][c];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    
    cout << Dfs(0, 0);
    
    return 0;
}