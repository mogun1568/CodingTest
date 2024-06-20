#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, answer;
int institute[8][8];
bool visited[8][8];
vector<pair<int, int>> v;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int Bfs(int r, int c) {
    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});
    int cnt = 0;
    bool checkVirus = false;

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        cnt++;
        if (institute[cr][cc] == 2)
            //cout << cr << " " << cc << "\n";
            checkVirus = true;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (institute[nr][nc] == 1)
                continue;
            
            if (visited[nr][nc])
                continue;
            
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    if (checkVirus) 
        cnt = 0;
    
    return cnt;
}

int FindZero() {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (institute[i][j] == 1) 
                continue;

            if (visited[i][j])
                continue;

            cnt += Bfs(i, j);
        }
    }

    return cnt;
}

void Solve() {
    for (int i = 0; i < v.size() - 2; i++) {
        for (int j = i + 1; j < v.size() - 1; j++) {
            for (int k = j + 1; k < v.size(); k++) {
                institute[v[i].first][v[i].second] = 1;
                institute[v[j].first][v[j].second] = 1;
                institute[v[k].first][v[k].second] = 1;
                answer = max(answer, FindZero());
                institute[v[i].first][v[i].second] = 0;
                institute[v[j].first][v[j].second] = 0;
                institute[v[k].first][v[k].second] = 0;
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
            cin >> institute[i][j];

            if (institute[i][j] == 0)
                v.push_back({i, j});
        }
    }

    Solve();

    cout << answer;
    
    return 0;
}