#include <iostream>
using namespace std;

int N, M, ans;
int room[50][50];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void Clean(int r, int c, int d) {
    if (room[r][c] == 0) {
        room[r][c] = -1;
        ans++;
    }

    for (int i = 1; i <= 4; i++) {
        int nd = (d - i + 4) % 4;
        int nr = r + dr[nd];
        int nc = c + dc[nd];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;

        if (room[nr][nc] == 0) {
            Clean(nr, nc, nd);
            return;
        }
    }

    int nd = (d + 2) % 4;
    int nr = r + dr[nd];
    int nc = c + dc[nd];
    if (room[nr][nc] == -1)
        Clean(nr, nc, d);

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c, d;
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> room[i][j];
    }

    Clean(r, c, d);

    cout << ans;
    
    return 0;
}