#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans;
int paper[500][500];
bool visited[500][500];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void DFS(int r, int c, int cnt, int sum) {
    if (cnt == 4) {
        ans = max(ans, sum);
        return;
    }

    int tCnt = 0, tSum = 0, tMin = 1000;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;

        if (visited[nr][nc])
            continue;

        if (cnt == 2) {
            tCnt++;
            tSum += paper[nr][nc];
            tMin = min(tMin, paper[nr][nc]);
        }

        visited[nr][nc] = true;
        DFS(nr, nc, cnt + 1, sum + paper[nr][nc]);
        visited[nr][nc] = false;
    }

    if (cnt == 2) {
        if (tCnt < 2)
            return;
        else if (tCnt == 2)
            ans = max(ans, sum + tSum);
        else
            ans = max(ans, sum + tSum - tMin);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> paper[i][j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            DFS(i, j, 1, paper[i][j]);
            visited[i][j] = false;
        }
    }

    cout << ans;
    
    return 0;
}