#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int m, n;

bool field[50][50];
bool visit[50][50];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

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

        for (int i = 0; i < 4; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }

            if (field[nx][ny] && !visit[nx][ny]) {
                visit[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, k, x, y, cnt;
    cin >> t;

    while (t > 0) {
        cnt = 0;
        cin >> m >> n >> k;

        S cab[k];
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            field[x][y] = 1;
            cab[i] = {x, y};
        }

        for (int i = 0; i < k; i++) {
            if (!visit[cab[i].x][cab[i].y]) {
                visit[cab[i].x][cab[i].y] = true;
                bfs(cab[i].x, cab[i].y);
                cnt++;
            }
        }
        cout << cnt << "\n";

        memset(field, false, sizeof(field));
        memset(visit, false, sizeof(visit));
        t--;
    }
    
    return 0;
}