#include <iostream>
#include <queue>
#include <string>

using namespace std;

int M, N, answer;
int maze[101][101];
bool visited[101][101];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void Bfs() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    visited[1][1] = true;
    pq.push({0, {1, 1}});

    while (!pq.empty()) {
        int wall = pq.top().first;
        int cr = pq.top().second.first;
        int cc = pq.top().second.second;
        pq.pop();

        if (cr == N && cc == M) {
            answer = wall;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > M)
                continue;

            if (visited[nr][nc])
                continue;

            visited[nr][nc] = true;
            if (maze[nr][nc] == 1)
                pq.push({wall + 1, {nr, nc}});
            else
                pq.push({wall, {nr, nc}});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N;
    
    string s;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 1; j <= M; j++) {
            maze[i][j] = s[j - 1] - '0';
        }
    }

    Bfs();

    cout << answer;
    
    return 0;
}