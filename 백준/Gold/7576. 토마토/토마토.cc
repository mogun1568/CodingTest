#include <iostream>
#include <queue>
using namespace std;

int M, N, cnt;
int box[1001][1001];
queue<pair<int, int>> q;

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int BFS() {
    int day;
    
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        cnt--;
        day = box[r][c] - 1;
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (box[nr][nc] != 0)
                continue;

            box[nr][nc] = box[r][c] + 1;
            q.push({nr, nc});
        }
    }

    if (cnt == 0)
        return day;
    else
        return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];

            if (box[i][j] == -1)
                continue;
            
            cnt++;  
            if (box[i][j] == 1)
                q.push({i, j});
        }
    }

    cout << BFS();
    
    return 0;
}