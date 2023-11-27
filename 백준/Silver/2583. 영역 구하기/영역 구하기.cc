#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
bool paper[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y) {
    int cnt = 1;
    queue<pair<int, int>> q;
    paper[x][y] = true;
    q.push({x, y});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if (!paper[nx][ny]) {
                paper[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, x1, y1, x2, y2;
    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                paper[x][y] = true;
            }
        } 
    }

    vector<int> area;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!paper[i][j]) {
                area.push_back(bfs(i, j));
            }
        }
    }

    sort(area.begin(), area.end());

    cout << area.size() << "\n";
    for (int i = 0; i < area.size(); i++) {
        cout << area[i] << " ";
    }

    return 0;
}