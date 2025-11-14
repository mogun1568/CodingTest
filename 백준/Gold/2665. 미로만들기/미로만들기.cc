#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
int rooms[51][51];
int visited[51][51];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void BFS() {
    queue<pair<int, int>> q;
    visited[1][1] = 1;
    q.push({1, 1});

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 1 || nr > n || nc < 1 || nc > n)
                continue;

            if (rooms[nr][nc] == 0) {
                if (visited[nr][nc] == 0 || visited[nr][nc] > visited[r][c] + 1) {
                    visited[nr][nc] = visited[r][c] + 1;
                    q.push({nr, nc});
                }
            }
            else {
                if (visited[nr][nc] == 0 || visited[nr][nc] > visited[r][c]) {
                    visited[nr][nc] = visited[r][c];
                    q.push({nr, nc});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string str;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (int j = 1; j <= n; j++)
            rooms[i][j] = str[j - 1] - '0';
    }

    BFS();

    cout << visited[n][n] - 1;
    
    return 0;
}