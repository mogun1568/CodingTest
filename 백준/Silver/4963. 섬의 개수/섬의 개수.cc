#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int w, h;

bool map[51][51];
bool visit[51][51];

int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[8] = {-1, 1, 0, 0, 1, 1, -1, -1};

struct S
{
    int x;
    int y;
};

void bfs(int x, int y) {
    queue<S> q;
    q.push({x, y});

    while (!q.empty()) {
        S s = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                continue;
            }

            if (map[nx][ny] && !visit[nx][ny]) {
                visit[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> w >> h;

        if (w == 0 && h == 0) {
            return 0;
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] && !visit[i][j]) {
                    visit[i][j] = true;
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";

        memset(map, false, sizeof(map));
        memset(visit, false, sizeof(visit));
    }
    
    return 0;
}