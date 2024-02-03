#include <iostream>
#include <queue>

using namespace std;

int box[1000][1000];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {-1, 1, 0, 0};

struct Tomato {
    int r;
    int c;
    int day;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n, cnt, result;
    cin >> m >> n;

    cnt = m * n;
    queue<Tomato> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];

            if (box[i][j] == 1) {
                q.push({i, j, 0});
            }

            if (box[i][j] != 0) {
                cnt--;
            }
        }
    }

    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int day = q.front().day;
        q.pop();

        result = day;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }

            if (box[nr][nc] == 0) {
                box[nr][nc] = 1;
                q.push({nr, nc, day + 1});
                cnt--;
            }
        }
    }

    if (cnt > 0) {
        cout << -1;
    } else {
        cout << result;
    }

    return 0;
}