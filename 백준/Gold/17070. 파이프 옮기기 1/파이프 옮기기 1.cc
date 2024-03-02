#include <iostream>

using namespace std;

int n, cnt;
int house[17][17];

void dfs(int r, int c, int d) {
    if (r == n && c == n) {
        cnt++;
    }

    if (d != 2) {
        if (c + 1 <= n && house[r][c + 1] != 1) {
            dfs(r, c + 1, 1);
        }
    }

    if (d != 1) {
        if (r + 1 <= n && house[r + 1][c] != 1) {
            dfs(r + 1, c, 2);
        }
    }

    if (r + 1 <= n && c + 1 <= n) {
        if (house[r][c + 1] != 1 && house[r + 1][c] != 1 && house[r + 1][c + 1] != 1) {
            dfs(r + 1, c + 1, 3);
        }    
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> house[i][j];
        }
    }

    dfs(1, 2, 1);

    cout << cnt;

    return 0;
}