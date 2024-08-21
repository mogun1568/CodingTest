#include <iostream>
#include <queue>

using namespace std;

int N, problem = 1;
int matrix[125][125];
int visited[125][125];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void Bfs() {
    queue<pair<int, int>> q;
    visited[0][0] = matrix[0][0];
    q.push({0, 0});

    int a = 0;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;

            int nCost = visited[cr][cc] + matrix[nr][nc];
            if (nCost >= visited[nr][nc])
                continue;

            visited[nr][nc] = nCost;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while (1) {
        cin >> N;
        if (N == 0)
            break;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
                visited[i][j] = 150000;
            }
        }
        
        Bfs();

        cout << "Problem " << problem++ << ": " << visited[N - 1][N - 1] << "\n";
    }
}