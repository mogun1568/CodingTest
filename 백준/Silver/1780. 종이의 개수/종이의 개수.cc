#include <iostream>

using namespace std;

int minusOne, zero, one;

int map[2187][2187];

void dfs(int r, int c, int size) {
    bool check = true;
    int num = map[r][c];

    if (size == 1) {
        if (num == -1) {
            minusOne++;
        } else if (num == 0) {
            zero++;
        } else {
            one++;
        }

        return;
    }

    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++) {
            if (num != map[i][j]) {
                check = false;
                int newSize = size / 3;

                dfs(r, c, newSize);
                dfs(r, c + newSize, newSize);
                dfs(r, c + 2 * newSize, newSize);
                dfs(r + newSize, c, newSize);
                dfs(r + newSize, c + newSize, newSize);
                dfs(r + newSize, c + 2 * newSize, newSize);
                dfs(r + 2 * newSize, c, newSize);
                dfs(r + 2 * newSize, c + newSize, newSize);
                dfs(r + 2 * newSize, c + 2 * newSize, newSize);

                break;
            }
        }

        if (!check) {
            break;
        }
    }

    if (check) {
        if (num == -1) {
            minusOne++;
        } else if (num == 0) {
            zero++;
        } else {
            one++;
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

    dfs(0, 0, n);

    cout << minusOne << '\n' << zero << '\n' << one;

    return 0;
}