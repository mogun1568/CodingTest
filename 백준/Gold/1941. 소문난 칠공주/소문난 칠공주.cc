#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

string group[5];
bool girl[25];
bool princess[5][5];
bool visited[5][5];
int ans;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool MoreThanFour() {
    int cnt = 0;
    for (int i = 0; i < 25; i++) {
        if (!girl[i])
            continue;
        
        int r = i / 5;
        int c = i % 5;
        if (group[r][c] == 'S')
            cnt++;
    }

    if (cnt >= 4)
        return true;
    else
        return false;
}

bool IsAdjacent() {
    memset(princess, false, sizeof(princess));
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    bool flag = false;
    for (int i = 0; i < 25; i++) {
        if (!girl[i])
            continue;
            
        int r = i / 5;
        int c = i % 5;
        princess[r][c] = true;

        if (!flag) {
            flag = true;
            visited[r][c] = true;
            q.push({r, c});
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        cnt++;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5)
                continue;

            if (!princess[nr][nc] || visited[nr][nc])
                continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    if (cnt == 7)
        return true;
    else
        return false;
}

void DFS(int idx, int cnt) {
    if (cnt == 7) {
        if (!MoreThanFour())
            return;

        if (!IsAdjacent())
            return;

        ans++;
        
        return;
    }

    for (int i = idx; i < 25; i++) {
        girl[i] = true;
        DFS(i + 1, cnt + 1);
        girl[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        cin >> group[i];

    DFS(0, 0);

    cout << ans;
    
    return 0;
}