#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 987654321

int N, M, emptyCnt, answer = INF;
char lab[50][50];
bool visited[50][50];
vector<pair<int, int>> virus;
bool useVirus[10];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void Bfs() {
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < virus.size(); i++) {
        if (useVirus[i]) {
            visited[virus[i].first][virus[i].second] = true;
            q.push({{virus[i].first, virus[i].second}, 0});
        }
    }

    int cnt = emptyCnt, minTime = 0;
    while (!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int ct = q.front().second;
        q.pop();

        if (lab[cr][cc] != '2') {
            cnt--;
            minTime = ct;
        }

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;

            if (visited[nr][nc] || lab[nr][nc] == '1')
                continue;

            visited[nr][nc] = true;
            q.push({{nr, nc}, ct + 1});
        }
    }

    if (cnt == 0)
        answer = min(answer, minTime);
}

void SelectVirus(int idx, int cnt) {
    if (cnt == M) {
        Bfs();
        return;
    }

    for (int i = idx; i < virus.size(); i++) {
        useVirus[i] = true;
        SelectVirus(i + 1, cnt + 1);
        useVirus[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> lab[i][j];

            if (lab[i][j] == '2')
                virus.push_back({i, j});
            else if (lab[i][j] == '0')
                emptyCnt++;
        }
    }

    SelectVirus(0, 0);

    if (answer == INF) {
        cout << -1;
        return 0;
    }
    
    cout << answer;
    
    return 0;
}