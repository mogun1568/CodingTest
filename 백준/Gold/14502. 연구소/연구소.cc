#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M, ans = 0;
int map[9][9];
bool visited[9][9];
vector<pair<int, int>> zero;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int BFS(int r, int c) {
    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});
    int cnt = 0;
    bool virusFlag = false;

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        cnt++;
        if (map[cr][cc] == 2)
            virusFlag = true;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (map[nr][nc] == 1)
                continue;

            if (visited[nr][nc])
                continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    if (virusFlag)
        return 0;

    return cnt;
}

int SpreadVirus() {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1)
                continue;

            if (visited[i][j])
                continue;

            cnt += BFS(i, j);
        }
    }

    return cnt;
}

void BuildWalls() {
    int size = zero.size();
    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                map[zero[i].first][zero[i].second] = 1;
                map[zero[j].first][zero[j].second] = 1;
                map[zero[k].first][zero[k].second] = 1;

                ans = max(ans, SpreadVirus());
                
                map[zero[i].first][zero[i].second] = 0;
                map[zero[j].first][zero[j].second] = 0;
                map[zero[k].first][zero[k].second] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 0)
                zero.push_back({i, j});
        }
    }

    BuildWalls();

    cout << ans;
    
    return 0;
}