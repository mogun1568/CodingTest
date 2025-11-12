#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 26

int ans = MAX;
int paper[10][10];
int color[6];

bool Check(int r, int c, int size) {
    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++) {
            if (paper[i][j] == 0)
                return false;
        }
    }

    return true;
}

void DFS(int r, int c, int cnt) {
    if (cnt > ans)
        return;
    
    while (paper[r][c] == 0) {
        c++;
        if (c >= 10) {
            r++;
            if (r >= 10) {
                ans = min(ans, cnt);
                return;
            }
            c = 0;
        }
    }

    for (int i = 5; i > 0; i--) {
        if (r + i > 10 || c + i > 10)
            continue;

        if (color[i] >= 5)
            continue;

        if (!Check(r, c, i))
            continue;

        color[i]++;
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++)
                paper[r + j][c + k] = 0;
        }

        DFS(r, c, cnt + 1);

        color[i]--;
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++)
                paper[r + j][c + k] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cin >> paper[i][j];
    }

    DFS(0, 0, 0);

    if (ans == MAX)
        cout << -1;
    else
        cout << ans;
    
    return 0;
}