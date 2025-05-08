#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int l;
pair<int, int> knight[2];
int visited[300][300];

int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void BFS() {
    queue<pair<int, int>> q;
    visited[knight[0].first][knight[0].second] = 1;
    q.push({knight[0].first, knight[0].second});

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == knight[1].first && c == knight[1].second) {
            cout << visited[r][c] - 1 << "\n";
            return;
        }

        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= l || nc < 0 || nc >= l)
                continue;

            if (visited[nr][nc] != 0)
                continue;

            visited[nr][nc] = visited[r][c] + 1;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, r, c;
    cin >> T;

    while (T--) {
        cin >> l;
        for (int i = 0; i < 2; i++) {
            cin >> r >> c;
            knight[i].first = r;
            knight[i].second = c;
        }
        memset(visited, 0, sizeof(visited));

        BFS();
    }
    
    return 0;
}