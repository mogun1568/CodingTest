#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, s;
int tube[201][201];
vector<pair<int, int>> virus[1001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0 ,-1, 1};

struct v {
    int x, y, s;
};

queue<v> q;
void bfs() {  
    while (!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int cs = q.front().s;
        q.pop();

        if (cs == s) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int ns = cs + 1;

            if (nx < 1 || nx > n || ny < 1 || ny > n) {
                continue;
            }

            if (tube[nx][ny] != 0) {
                continue;
            }

            tube[nx][ny] = tube[cx][cy];
            q.push({nx, ny, ns});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int k, x, y;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tube[i][j];

            if (tube[i][j] != 0) {
                virus[tube[i][j]].push_back({i, j});
            }
        }
    }

    cin >> s >> x >> y;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < virus[i].size(); j++) {         
            int cx = virus[i][j].first;
            int cy = virus[i][j].second;

            q.push({cx, cy, 0});
        }
    }

    bfs();
    
    cout << tube[x][y];
    
    return 0;
}