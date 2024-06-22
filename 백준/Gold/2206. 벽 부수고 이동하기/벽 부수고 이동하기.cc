#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
bool map[1001][1001];
int visited[1001][1001][2];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};


int Bfs() {
    queue<pair<pair<int, int>, int>> q;
    visited[1][1][0] = 1;
    q.push({{1, 1}, 0});

    while (!q.empty()) {
        int r = q.front().first.first;
		int c = q.front().first.second;
		int wall = q.front().second;
        q.pop();

        if (r == N && c == M)
            return visited[r][c][wall];

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > M)
                continue;

            if (map[nr][nc] && wall == 0) {
                visited[nr][nc][1] = visited[r][c][0] + 1;
                q.push({{nr, nc}, 1});
            }
            else if (!map[nr][nc] && visited[nr][nc][wall] == 0) {
                visited[nr][nc][wall] = visited[r][c][wall] + 1;
                q.push({{nr, nc}, wall});
            }
            
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            map[i][j] = s[j - 1] - '0';
        }
    }

    cout << Bfs();
    
    return 0;
}