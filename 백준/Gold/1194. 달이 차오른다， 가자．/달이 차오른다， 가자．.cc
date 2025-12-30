#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct State {
    int r, c;
    int key;
    int cnt;
};

int N, M;
string maze[50];
bool visited[50][50][1 << 6];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int BFS(int r, int c) {
    queue<State> q;
    visited[r][c][0] = true;
    q.push({r, c, 0, 0});

    while (!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        int cKey = q.front().key;
        int cnt = q.front().cnt;
        q.pop();

        if (maze[cr][cc] == '1')
            return cnt;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (maze[nr][nc] == '#')
                continue;

            int nKey = cKey;
            if (maze[nr][nc] >= 'a' && maze[nr][nc] <= 'f')
                nKey |= 1 << (maze[nr][nc] - 'a');
            else if (maze[nr][nc] >= 'A' && maze[nr][nc] <= 'F') {
                if ( !((1 << (maze[nr][nc] - 'A')) & nKey) )
                    continue;
            }

            if (visited[nr][nc][nKey])
                continue;

            visited[nr][nc][nKey] = true;
            q.push({nr, nc, nKey, cnt + 1});
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int sr, sc;
    for (int i = 0; i < N; i++) {
        cin >> maze[i];

        for (int j = 0; j < M; j++) {
            if (maze[i][j] == '0') {
                sr = i;
                sc = j;
            }
        }
    }

    cout << BFS(sr, sc);
    
    return 0;
}