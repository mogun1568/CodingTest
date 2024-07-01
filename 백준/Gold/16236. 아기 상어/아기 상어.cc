#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, R, C, Ssize = 2, eat, answer;
int space[20][20];
int visited[20][20];

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

int Bfs() {
    memset(visited, 0, sizeof(visited));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int dist = 0;
    queue<pair<int, int>> q;
    visited[R][C] = 1;
    q.push({R, C});
    
    while (!q.empty()) {
        int cr = q.front().first; 
        int cc = q.front().second;
        q.pop();

        if (visited[cr][cc] == dist)
            break;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;

            if (space[nr][nc] > Ssize || visited[nr][nc] != 0)
                continue;

            visited[nr][nc] = visited[cr][cc] + 1;
            if (space[nr][nc] == 0 || space[nr][nc] == Ssize)
                q.push({nr, nc});
			else if (space[nr][nc] < Ssize) {
				dist = visited[nr][nc];
				pq.push({nr, nc});
			}
        }
    }

    if (pq.empty())
        return 0;

    space[R][C] = 0;
    R = pq.top().first;
    C = pq.top().second;
    space[R][C] = 9;

    eat++;
    if (eat == Ssize) {
        Ssize++;
        eat = 0;
    }   

    return visited[R][C] - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space[i][j];

            if (space[i][j] == 9) {
                R = i;
                C = j;
            }
        }
    }

    int time = -1;
    while (time != 0) {
        time = Bfs();
        answer += time;
    }

    cout << answer;
    
    return 0;
}