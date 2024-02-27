#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool state[5][8];
int cogwheel[5];
bool rotation[5][2];

void dfs(int n, int d, int m) {
    if (d == 1) {
        cogwheel[n] = (cogwheel[n] + 7) % 8;
    } else {
        cogwheel[n] = (cogwheel[n] + 1) % 8;
    }

    if (n > 1 && m != 1) {
        if (rotation[n][0]) {
            dfs(n - 1, d * -1, -1);
        }
    }

    if (n < 4 && m != -1) {
        if (rotation[n][1]) {
            dfs(n + 1, d * -1, 1);
        }
    }
}

void check() {
    memset(rotation, false, sizeof(rotation));

    for (int i = 1; i < 4; i++) {
        int r, l;
        r = (cogwheel[i] + 2) % 8;
        l = (cogwheel[i + 1] + 6) % 8;

        if (state[i][r] != state[i + 1][l]) {
            rotation[i][1] = true;
            rotation[i + 1][0] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    for (int i = 1; i <= 4; i++) {
        cin >> s;
        for (int j = 0; j < 8; j++) {
            state[i][j] = s[j] - '0';
        }
    }
    
    int k, n, d, sum = 0, p = 1;
    cin >> k;

    while (k--) {
        cin >> n >> d;

        check();
        dfs(n, d, 0);
    }

    for (int i = 1; i <= 4; i++) {
        if (state[i][cogwheel[i]]) {
            sum += p;
        }
        p *= 2;
    }

    cout << sum;

    return 0;
}