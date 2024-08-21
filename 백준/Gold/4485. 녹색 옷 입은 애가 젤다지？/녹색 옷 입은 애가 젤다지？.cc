#include <iostream>
#include <queue>

using namespace std;

int N, problem = 1;
int matrix[125][125];
int visited[125][125];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void Bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visited[0][0] = matrix[0][0];
    pq.push({0, 0});

    while (!pq.empty()) {
        int cr = pq.top().first;
        int cc = pq.top().second;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;

            int nCost = visited[cr][cc] + matrix[nr][nc];
            if (nCost >= visited[nr][nc])
                continue;

            visited[nr][nc] = nCost;
            pq.push({nr, nc});
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