#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

char puyo[12][6];
bool visited[12][6];
int answer;
bool flag;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void Bfs(int r, int c) {
    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});

    char color = puyo[r][c];
    queue<pair<int, int>> temp;
    
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        temp.push({cr, cc});

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= 12 || nc < 0 || nc >= 6)
                continue;

            if (visited[nr][nc] || puyo[nr][nc] != color)
                continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    if (temp.size() < 4)
        return;

    flag = true;
    
    while (!temp.empty()) {
        int cr = temp.front().first;
        int cc = temp.front().second;
        temp.pop();

        puyo[cr][cc] = '.';
    }
}

void MovePuyo() {
    for (int i = 0; i < 6; i++) {
        for (int j = 10; j >= 0; j--) {
            if (puyo[j][i] == '.')
             continue;

            char color = puyo[j][i];
            int r = j + 1;
            while (r < 12 && puyo[r][i] == '.')
                r++;

            puyo[j][i] = '.';
            puyo[r - 1][i] = color;
        }
    }
}

void CheckSeries() {
    memset(visited, false, sizeof(visited));
    flag = false;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (puyo[i][j] != '.' && !visited[i][j])
                Bfs(i, j);
        }
    }
    
    if (flag) {
        answer++;
        MovePuyo();
        CheckSeries();
    }  
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 12; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 6; j++)
            puyo[i][j] = s[j];
    }

    CheckSeries();

    cout << answer;
    
    return 0;
}