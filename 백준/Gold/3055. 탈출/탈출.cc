#include <iostream>
#include <queue>

using namespace std;

int R, C, answer;
char forest[50][50];
bool visited[50][50];
queue<pair<int, int>> water, S;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

bool Solve() {
    int t = S.size();
    while (t--) {
        int cr = S.front().first;
        int cc = S.front().second;
        S.pop();

        if (forest[cr][cc] == '*')
            continue;
        else if (forest[cr][cc] == 'D')
            return true;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;

            if (visited[nr][nc] || forest[nr][nc] == '*' || forest[nr][nc] == 'X')
                continue;

            visited[nr][nc] = true;
            S.push({nr, nc});
        }
    }

    t = water.size();
    while (t--) {
        int cr = water.front().first;
        int cc = water.front().second;
        water.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;

            if (forest[nr][nc] != '.')
                continue;

            forest[nr][nc] = '*';
            water.push({nr, nc});
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> forest[i][j];

            if (forest[i][j] == '*')
                water.push({i, j});
            else if (forest[i][j] == 'S') {
                visited[i][j] = true;
                S.push({i, j});
                forest[i][j] = '.';
            }               
        }
    }

    while(!S.empty()) {
        if (Solve()) {
            cout << answer;
            return 0;
        }
        
        answer++;
    }

    cout << "KAKTUS";
    
    return 0;
}