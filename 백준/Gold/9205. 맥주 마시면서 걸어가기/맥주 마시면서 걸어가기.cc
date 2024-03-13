#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int n;
int coor[2][2];
pair<int, int> p[100];
int visited[100];

bool bfs() {
    queue<pair<int, int>> q;
    q.push({coor[0][0], coor[0][1]});
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (abs(coor[1][0] - x) + abs(coor[1][1] - y) <= 1000) {
            return true;
        }

        for (int i = 0; i < n; i++) {
            int nx = p[i].first;
            int ny = p[i].second;

            if (visited[i]) {
                continue;
            }

            if (abs(nx - x) + abs(ny - y) > 1000) {
                continue;
            }

            visited[i] = true;
            q.push({nx, ny});
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        cin >> coor[0][0] >> coor[0][1];

        for (int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
        }
    
        cin >> coor[1][0] >> coor[1][1];

        if (bfs()) {
            cout << "happy\n";
        } else {
            cout << "sad\n";
        }

        memset(visited, false, sizeof(visited));
    }

    return 0;
}