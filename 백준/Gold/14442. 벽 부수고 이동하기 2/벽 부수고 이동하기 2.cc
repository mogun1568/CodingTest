#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Location {
    int r, c;
    int k;
    int cnt;
};

int N, M, K;
bool map[1001][1001];
bool visited[1001][1001][11];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int BFS() {
    queue<Location> q;
    visited[1][1][0] = true;
    q.push({1, 1, 0, 1});

    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int k = q.front().k;
        int cnt = q.front().cnt;
        q.pop();

        if (r == N && c == M)
            return cnt;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > M)
                continue;

            if (map[nr][nc] == 1) {
                if (k < K && !visited[nr][nc][k + 1]) {
                    visited[nr][nc][k + 1] = true;
                    q.push({nr, nc, k + 1, cnt + 1});
                }
            }
            else {
                if (!visited[nr][nc][k]) {
                    visited[nr][nc][k] = true;
                    q.push({nr, nc, k, cnt + 1});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    string s;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 1; j <= M; j++)
            map[i][j] = s[j - 1] - '0';
    }

    cout << BFS();
    
    return 0;
}