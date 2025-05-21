#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M, N;
bool paper[100][100];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int BFS(int r, int c) {
    int cnt = 0;
    queue<pair<int, int>> q;
    paper[r][c] = true;
    q.push({r, c}); 

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

            if (paper[nr][nc])
                continue;

            paper[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int K, x1, y1, x2, y2;
    cin >> M >> N >> K;
    while (K--) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++)
                paper[i][j] = true;
        }
    }

    vector<int> area;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!paper[i][j])
                area.push_back(BFS(i, j));
        }
    }
    sort(area.begin(), area.end());

    cout << area.size() << "\n";
    for (auto a : area)
        cout << a << " ";
    
    return 0;
}