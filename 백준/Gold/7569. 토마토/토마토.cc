#include <iostream>
#include <queue>
using namespace std;

struct tomato {
    int f;
    int r;
    int c;
};

int M, N, H, ans, cnt;
int box[100][100][100];
queue<tomato> q;

int df[6] = {-1, 1, 0, 0, 0, 0};
int dr[6] = {0, 0, 0, 0, 1, -1};
int dc[6] = {0, 0, -1, 1, 0, 0};

void BFS() {
    while (!q.empty()) {
        int cf = q.front().f;
        int cr = q.front().r;
        int cc = q.front().c;
        q.pop();

        ans = box[cf][cr][cc] - 1;
        cnt--;

        for (int i = 0; i < 6; i++) {
            int nf = cf + df[i];
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nf < 0 || nf >= H || nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (box[nf][nr][nc] != 0)
                continue;

            box[nf][nr][nc] = box[cf][cr][cc] + 1;
            q.push({nf, nr, nc});
        }      
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];

                if (box[i][j][k] == 1)
                    q.push({i, j, k});
                if (box[i][j][k] != -1)
                    cnt++;
            }
        }
    }

    BFS();

    if (cnt == 0)
        cout << ans;
    else
        cout << -1;
    
    return 0;
}