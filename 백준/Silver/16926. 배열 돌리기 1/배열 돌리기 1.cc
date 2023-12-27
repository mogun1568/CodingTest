#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[300][300];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void rotate(int box) {
    for (int i = 0; i < box; i++) {
        int startValue = a[i][i];
        int r = i;
        int c = i;
        int dir = 0;

        while (1) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr == i && nc == i) {
                break;
            }

            if (nr < i || nr >= n - i || nc < i || nc >= m - i) {
                dir++;
                continue;
            } 

            a[r][c] = a[nr][nc];
            r = nr;
            c = nc;
        }

        a[i + 1][i] = startValue;
    }
    

    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int r;
    cin >> n >> m >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (r--) {
        rotate(min(n, m) / 2);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}