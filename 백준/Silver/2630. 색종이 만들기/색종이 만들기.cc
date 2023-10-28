#include <iostream>

using namespace std;

int white, blue;

int map[128][128];

void dfs(int rs, int re, int cs, int ce) {
    bool check = true, color = map[rs][cs];

    if (rs + 1 == re) {
        if (color == 0) {
            white++;
        } else {
            blue++;
        }

        return;
    }

    for (int i = rs; i < re; i++) {
        for (int j = cs; j < ce; j++) {
            if (color != map[i][j]) {
                check = false;

                dfs(rs, (rs + re) / 2, cs, (cs + ce) / 2);
                dfs(rs, (rs + re) / 2, (cs + ce) / 2, ce);
                dfs((rs + re) / 2, re, cs, (cs + ce) / 2);
                dfs((rs + re) / 2, re, (cs + ce) / 2, ce);
    
                break;
            }
        }

        if (!check) {
            break;
        }
    }

    if (check) {
        if (color == 0) {
            white++;
        } else {
            blue++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0, n, 0, n);

    cout << white << '\n' << blue;

    return 0;
}