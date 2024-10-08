#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N, M, D, answer;
bool board[16][16];
int archer[3];
int enemy[16][16];
bool visited[16][16];

int dr[] = {0, -1, 0};
int dc[] = {-1, 0, 1};

bool EnemyCheck(int idx) {
    for (int i = 1; i <= idx; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j] && enemy[i][j] == 0) {
                return true;
            }
        }
    }

    return false;
}

void Bfs(int idx, int c) {
    memset(visited, 0, sizeof(visited));
    visited[idx][c] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push({{idx, c}, 1});

    while(!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int cd = q.front().second;
        q.pop();

        if (board[cr][cc]) {
            if (enemy[cr][cc] == 0 || enemy[cr][cc] == idx) {
                enemy[cr][cc] = idx;
                return;
            }
        }

        if (cd == D)
            continue;

        for (int i = 0; i < 3; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 1 || nr > idx || nc < 1 || nc > M)
                continue;

            if (visited[nr][nc])
                continue;

            visited[nr][nc] = true;
            q.push({{nr, nc}, cd + 1});
        }
    }
}

void KillEnemy() {
    memset(enemy, 0, sizeof(enemy));
    int idx = N;
    while (idx > 0) {
        if (!EnemyCheck(idx))
            break;

        for (int i = 0; i < 3; i++)
            Bfs(idx, archer[i]);

        idx--;
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (enemy[i][j] != 0)
                cnt++;
        }
    }

    answer = max(answer, cnt);
}

void SelectArcher(int idx) {
    if (idx == 3) {
        KillEnemy();
        return;
    }

    for (int i = archer[idx - 1] + 1; i <= M; i++) {
        archer[idx] = i;
        SelectArcher(idx + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> D;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];
    }

    SelectArcher(0);

    cout << answer;
    
    return 0;
}