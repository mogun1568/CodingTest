#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int R, C, answer;
char board[20][20];
bool alpha[26];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void Dfs(int r, int c, int cnt) {
    answer = max(answer, cnt);
    
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
            continue;

        int idx = board[nr][nc] - 'A';
        if (alpha[idx])
            continue;

        alpha[idx] = true;
        Dfs(nr, nc, cnt + 1);
        alpha[idx] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    alpha[board[0][0] - 'A'] = true;
    Dfs(0, 0, 1);

    cout << answer;
    
    return 0;
}