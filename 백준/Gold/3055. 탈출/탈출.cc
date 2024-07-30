#include <iostream>
#include <queue>

using namespace std;

int R, C, answer;
char forest[50][50];
bool visited[50][50];
queue<pair<pair<int, int>, int>> water, S;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

bool Solve() {
    while (!S.empty()) {
        int cr = S.front().first.first;
        int cc = S.front().first.second;
        int cm = S.front().second;
        
        if (cm == answer + 1)
            break;  
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
            S.push({{nr, nc}, cm + 1});
        }
    }

    while (!water.empty()) {
        int cr = water.front().first.first;
        int cc = water.front().first.second;
        int cm = water.front().second;
        
        if (cm == answer + 1)
            break;  
        water.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;

            if (forest[nr][nc] != '.')
                continue;

            forest[nr][nc] = '*';
            water.push({{nr, nc}, cm + 1});
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
                water.push({{i, j}, 0});
            else if (forest[i][j] == 'S') {
                visited[i][j] = true;
                S.push({{i, j}, 0});
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