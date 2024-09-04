#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, answer;
int paper[100][100];
bool visited[100][100];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool Bfs() {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.push({0, 0});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (visited[nr][nc])
                continue;

            if (paper[nr][nc] > 0) {
                paper[nr][nc]++;
            }
            else {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    bool check = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (paper[i][j] > 2)
                paper[i][j] = 0;
            else if (paper[i][j] != 0) {
                paper[i][j] = 1;
                check = true;
            }     
        }
    }

    return check;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    bool check = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];

            if (paper[i][j] == 1)
                check = true;
        }
    }

    if (!check) {
        cout << 0;
        return 0;
    }

    while (Bfs()) {
        answer++;
    }

    cout << answer + 1;
    
    return 0;
}