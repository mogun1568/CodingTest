#include <iostream>
#include <string>
using namespace std;

int R, C, ans;
char city[10001][501];
bool isConnected;

int dr[3] = {-1, 0, 1};
int dc[3] = {1, 1, 1};

void DFS(int r, int c) {
    if (c == C) {
        ans++;
        isConnected = true;
        return;
    }
    
    for (int i = 0; i < 3; i++) {
        if (isConnected)
            return;
        
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (nr < 1 || nr > R || nc < 1 || nc > C)
            continue;

        if (city[nr][nc] == 'x' || city[nr][nc] == 'o')
            continue;

        city[nr][nc] = 'o';
        DFS(nr, nc);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    string s;
    for (int i = 1; i <= R; i++) {
        cin >> s;
        for (int j = 1; j <= C; j++)
            city[i][j] = s[j - 1];
    }

    for (int i = 1; i <= R; i++) {
        isConnected = false;
        DFS(i, 1);
    }

    cout << ans;
    
    return 0;
}