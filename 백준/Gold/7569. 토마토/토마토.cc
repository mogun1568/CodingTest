#include <iostream>
#include <queue>

using namespace std;

int box[100][100][100];

int ds[6] = {-1, 1, 0, 0, 0, 0};
int dr[6] = {0, 0, 0, 0, 1, -1};
int dc[6] = {0, 0, -1, 1, 0, 0};

struct tomato {
    int s;
    int r;
    int c;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n, h, cnt, result;
    cin >> m >> n >> h;

    cnt = m * n * h;
    queue<tomato> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> box[i][j][k];

                if (box[i][j][k] == 1) {
                    q.push({i, j, k});
                }

                if (box[i][j][k] != 0) {
                    cnt--;
                }
            }
        }
    }

    while (!q.empty()) {
        int s = q.front().s;
        int r = q.front().r;
        int c = q.front().c;
        q.pop();

        result = box[s][r][c] - 1;

        for (int i = 0; i < 6; i++) {
            int ns = s + ds[i];
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (ns < 0 || ns >= h || nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }

            if (box[ns][nr][nc] != 0) {
                continue;
            }

            box[ns][nr][nc] = box[s][r][c] + 1;
            q.push({ns, nr, nc});
            cnt--;
        }
    }

    if (cnt > 0) {
        cout << -1;
    } else {
        cout << result;
    }
    
    return 0;
}