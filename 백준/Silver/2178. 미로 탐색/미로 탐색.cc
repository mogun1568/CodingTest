#include <iostream>
#include <queue>

using namespace std;

int n, m;

int map[101][101];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int curR = r + dr[i];
            int curC = c + dc[i];

            if (curR < 1 || curR > n || curC < 1 || curC > m) {
                continue;
            }

            if (map[curR][curC] == 1) {
                map[curR][curC] = map[r][c] + 1;
                q.push({curR, curC});
            }
        } 
    }

    return map[n][m];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            map[i][j] = s[j - 1] - '0';
        }
    }

    cout << bfs(1, 1);
    
    return 0;
}