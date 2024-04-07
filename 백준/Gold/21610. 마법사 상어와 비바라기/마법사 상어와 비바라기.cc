#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int a[51][51];
bool visited[51][51];
vector<pair<int, int>> cloud;

int dr[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dc[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

void solve(int d, int s) {
    for (int i = 0; i < cloud.size(); i++) {
        // 1
        int r = cloud[i].first;
        int c = cloud[i].second;

        int nr = r + dr[d] * s;
        int nc = c + dc[d] * s;
        while (nr <= 0 || nc <= 0) {
            nr += n;
            nc += n;
        }
        nr %= n;
        nc %= n;
        if (nr == 0) { nr = n; }
        if (nc == 0) { nc = n; }

        cloud[i].first = nr;
        cloud[i].second = nc;

        // 2
        a[nr][nc]++;
        visited[nr][nc] = true;
    }

    
    // 4
    for (int i = 0; i < cloud.size(); i++) {
        int cnt = 0;
        int r = cloud[i].first;
        int c = cloud[i].second;

        for (int i = 2; i <= 8; i += 2) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 1 || nr > n || nc < 1 || nc > n) {
                continue;
            }

            if (a[nr][nc] > 0) {
                cnt++;
            }
        }

        a[r][c] += cnt;
    }

    // 3
    cloud.clear();

    // 5
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] >= 2 && !visited[i][j]) {
                cloud.push_back({i, j});
                a[i][j] -= 2;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int m, d, s, cnt = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    cloud.push_back({n, 1});
    cloud.push_back({n, 2});
    cloud.push_back({n - 1, 1});
    cloud.push_back({n - 1, 2});
    for (int i = 0; i < m; i++) {
        cin >> d >> s;
        solve(d, s);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt += a[i][j];
        }
    }

    cout << cnt;
    
    return 0;
}