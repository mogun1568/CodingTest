#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, T;
int castle[101][101];
bool visited[101][101][2];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct Coor {
    int r;
    int c;
    bool sword;
    int cnt;
};

void Bfs() {
    queue<Coor> q;
    visited[1][1][false] = 1;
    q.push({1, 1, false, 0});

    while (!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        bool sword = q.front().sword;
        int cnt = q.front().cnt;
        q.pop();

        if (cnt > T) {
            cout << "Fail";
            return;
        }
        
        if (cr == N & cc == M) {
            cout << cnt;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            bool nSword = sword;
            int nCnt = cnt + 1;

            if (nr <= 0 || nr > N || nc <= 0 || nc > M) {
                continue;
            }

            if (castle[nr][nc] == 2) {
                nSword = true;
            }

            if (visited[nr][nc][nSword]) {
                continue;
            }

            if (castle[nr][nc] == 1 && !nSword) {
                continue;
            }
            
            visited[nr][nc][nSword] = true;
            q.push({nr, nc, nSword, nCnt});
        }
    }

    cout << "Fail";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> castle[i][j];
        }
    }

    Bfs();
    
    return 0;
}