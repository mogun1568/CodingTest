#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
int maze[101][101];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int BFS() {
    queue<pair<int, int>> q;
    maze[1][1] = 2;
    q.push({1, 1});

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == N && c == M)
            return maze[r][c] - 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > M)
                continue;

            if (maze[nr][nc] != 1)
                continue;

            maze[nr][nc] = maze[r][c] + 1;
            q.push({nr, nc});
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    string str;
    for (int i = 1; i <= N; i++) {
        cin >> str;
        for (int j = 1; j <= M; j++)
            maze[i][j] = str[j - 1] - '0';
    }

    cout << BFS();
    
    return 0;
}