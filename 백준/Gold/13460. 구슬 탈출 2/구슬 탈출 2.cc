#include <iostream>
#include <queue>

using namespace std;

int n, m;
char map[10][10];
bool visit[10][10][10][10];

int dx[4] = {0, 0, -1, 1};  // 왼, 오, 위, 아래
int dy[4] = {-1, 1, 0, 0};

struct bead
{
    int rx, ry; // 빨간 구슬 좌표
    int bx, by; // 파란 구슬 좌표
    int cnt = 0;
};

// 구슬을 한 방향 끝까지 이동라는 함수
void move(int& x, int& y, int& dis, int i) {
    while (map[x + dx[i]][y + dy[i]] != '#' && map[x][y] != 'O') {
        x += dx[i];
        y += dy[i];
        dis += 1;
    }
}

int main()
{
    bead start;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'R') {
                start.rx = i;
                start.ry = j;
                map[i][j] = '.';
            }
            if (map[i][j] == 'B') {
                start.bx = i;
                start.by = j;
                map[i][j] = '.';
            }
        }
    }

    queue<bead> q;
    q.push(start);
    visit[start.rx][start.ry][start.bx][start.by] = true;

    while (!q.empty()) {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int cnt = q.front().cnt;

        q.pop();

        if (cnt >= 10) {
           break;
        }

        for (int i = 0; i < 4; i++) {
            int curRX = rx, curRY = ry, disR = 0;
            int curBX = bx, curBY = by, disB = 0;
            move(curRX, curRY, disR, i);
            move(curBX, curBY, disB, i);

            if (map[curBX][curBY] == 'O') {
                continue;
            }
            if (map[curRX][curRY] == 'O') {
                cout << cnt + 1 << endl;
                return 0;
            }

            if (curRX == curBX && curRY == curBY) {
                if (disR > disB) {
                    curRX -= dx[i];
                    curRY -= dy[i];
                } else {
                    curBX -= dx[i];
                    curBY -= dy[i];
                }
            }

            if (visit[curRX][curRY][curBX][curBY]) {
                continue;
            }

            visit[curRX][curRY][curBX][curBY] = true;

            q.push({curRX, curRY, curBX, curBY, cnt + 1});
        }
    }

    cout << -1 << endl;

    return 0;
}