#include <iostream>
using namespace std;

int N, ans;
int sand[499][499];
bool visited[499][499];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};

void moveSand(int r, int c, int s) {
    if (s == 0)
        return;

    if (r < 0 || r >= N || c < 0 || c >= N) {
        ans += s;
        return;
    }

    sand[r][c] += s;
}

void scatter(int r, int c, int d) {
    int cs = sand[r][c];
    sand[r][c] = 0;
    int rs = cs;
    
    // 1%
    int nr = r + dr[(d + 1) % 4] + dr[(d + 2) % 4];
    int nc = c + dc[(d + 1) % 4] + dc[(d + 2) % 4];
    int ss = cs / 100;
    moveSand(nr, nc, ss);
    nr = r + dr[(d + 3) % 4] + dr[(d + 2) % 4];
    nc = c + dc[(d + 3) % 4] + dc[(d + 2) % 4];
    moveSand(nr, nc, ss);
    rs -= ss * 2;

    // 2%
    nr = r + dr[(d + 1) % 4] * 2;
    nc = c + dc[(d + 1) % 4] * 2;
    ss = cs * 2 / 100;
    moveSand(nr, nc, ss);
    nr = r + dr[(d + 3) % 4] * 2;
    nc = c + dc[(d + 3) % 4] * 2;
    moveSand(nr, nc, ss);
    rs -= ss * 2;

    // 5%
    nr = r + dr[d] * 2;
    nc = c + dc[d] * 2;
    ss = cs * 5 / 100;
    moveSand(nr, nc, ss);
    rs -= ss;

    // 7%
    nr = r + dr[(d + 1) % 4];
    nc = c + dc[(d + 1) % 4];
    ss = cs * 7 / 100;
    moveSand(nr, nc, ss);
    nr = r + dr[(d + 3) % 4];
    nc = c + dc[(d + 3) % 4];
    moveSand(nr, nc, ss);
    rs -= ss * 2;

    // 10%
    nr = r + dr[(d + 1) % 4] + dr[d];
    nc = c + dc[(d + 1) % 4] + dc[d];
    ss = cs * 10 / 100;
    moveSand(nr, nc, ss);
    nr = r + dr[(d + 3) % 4] + dr[d];
    nc = c + dc[(d + 3) % 4] + dc[d];
    moveSand(nr, nc, ss);
    rs -= ss * 2;

    // a
    nr = r + dr[d];
    nc = c + dc[d];
    moveSand(nr, nc, rs);
}

void moveTornado() {
    int r = N / 2;
    int c = N / 2;
    int d = 3;
    visited[r][c] = true;

    while (r != 0 || c != 0) {
        int nd = (d + 1) % 4;
        int nr = r + dr[nd];
        int nc = c + dc[nd]; 

        if (visited[nr][nc])
            nd = d;
        d = nd;

        r += dr[d];
        c += dc[d];
        visited[r][c] = true;

        scatter(r, c, d);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> sand[i][j];
    }

    moveTornado();

    cout << ans;
    
    return 0;
}