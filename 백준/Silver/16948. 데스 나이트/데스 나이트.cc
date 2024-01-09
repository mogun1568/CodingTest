#include <iostream>
#include <queue>

using namespace std;

int n, r2, c2;
bool visited[200][200];

int dr[6] = {-2, -2, 0, 0, 2, 2};
int dc[6] = {-1, 1, -2, 2, -1, 1};

struct Knight {
    int r;
    int c;
    int cnt;
};

int bfs (int r, int c) {
    if (r == r2 && c == c2) {
        return 0;
    }
    
    queue<Knight> q;
    visited[r][c] = true;
    q.push({r, c, 0});

    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int cnt = q.front().cnt;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                continue;
            }

            if (visited[nr][nc]) {
                continue;
            }

            if (nr == r2 && nc == c2) {
                return cnt + 1;
            }

            visited[nr][nc] = true;
            q.push({nr, nc, cnt + 1});
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int r1, c1;
    cin >> n >> r1 >> c1 >> r2 >> c2;

    cout << bfs(r1, c1);
    
    return 0;
}