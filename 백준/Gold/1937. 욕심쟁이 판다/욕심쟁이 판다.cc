#include <iostream>
#include <algorithm>

using namespace std;

int n, answer;
int forest[500][500];
int dp[500][500];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int Dfs(int r, int c) {
    if (dp[r][c] != 0)
        return dp[r][c];

    dp[r][c] = 1;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= n)
            continue;

        if (forest[nr][nc] <= forest[r][c])
            continue;

        dp[r][c] = max(dp[r][c], Dfs(nr, nc) + 1);
    }

    return dp[r][c];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> forest[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer = max(answer, Dfs(i, j));
        }
    }

    cout << answer;
    
    return 0;
}