#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
bool map[25][25];
bool visited[25][25];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

int BFS(int r, int c) {
    queue<pair<int, int>> q;
    visited[r][c] = true;
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

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;

            if (!map[nr][nc] || visited[nr][nc])
                continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    return cnt;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++)
            map[i][j] = s[j] - '0';
    }

    vector<int> v;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] && !visited[i][j])
                v.push_back(BFS(i, j));
        }
    }
    sort(v.begin(), v.end());

    cout << v.size() << "\n";
    for (auto i : v)
        cout << i << "\n";
    
    return 0;
}