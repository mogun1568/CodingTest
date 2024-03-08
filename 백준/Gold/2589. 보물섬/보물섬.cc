#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
bool land[50][50];
int arr[50][50];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs(int r, int c) {
    int cnt;
    queue<pair<int, int>> q;
    arr[r][c] = 1;
    q.push({r, c});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        cnt = arr[cr][cc];

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }

            if (!land[nr][nc] || arr[nr][nc] != 0) {
                continue;
            }

            arr[nr][nc] = arr[cr][cc] + 1;
            q.push({nr, nc});
        }
    }

    return cnt - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int result = 0;
    string s;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'L') {
                land[i][j] = true;
            } else {
                land[i][j] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (land[i][j]) {
                memset(arr, 0, sizeof(arr));
                result = max(result, bfs(i, j));
            }
        } 
    }

    cout << result;

    return 0;
}