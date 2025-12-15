#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

int N, M;
string map[1000];
int blockNum[1000][1000];
int blockCnt[1000001];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void BFS(int r, int c, int num) {
    queue<pair<int, int>> q;
    blockNum[r][c] = num;
    q.push({r, c});
    int cnt = 0;

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (map[nr][nc] == '1')
                continue;

            if (blockNum[nr][nc] != 0)
                continue;

            blockNum[nr][nc] = num;
            q.push({nr, nc});
        }
    }

    blockCnt[num] = cnt;
}

void solve(int r, int c) {
    set<int> s;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;

        s.insert(blockNum[nr][nc]);
    }

    int cnt = 1;
    for (auto num : s)
        cnt += blockCnt[num];
    
    map[r][c] = (cnt % 10) + '0';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> map[i];

    int num = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == '1')
                continue;

            if (blockNum[i][j] != 0)
                continue;

            BFS(i, j, num++);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == '1')
                solve(i, j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << map[i][j];
        cout << "\n";
    }
    
    return 0;
}