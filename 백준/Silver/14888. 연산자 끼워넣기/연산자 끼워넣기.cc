#include <iostream>

using namespace std;

int a[11];
int op[4];
int n, maxResult = -1000000001, minResult = 1000000001;

void dfs(int result, int aIdx) {
    if (aIdx == n) {
        if (result > maxResult) {
            maxResult = result;
        }
        if (result < minResult) {
            minResult = result;
        }

        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;

            if (i == 0) {
                dfs(result + a[aIdx], aIdx + 1);
            } else if (i == 1) {
                dfs(result - a[aIdx], aIdx + 1);
            } else if (i == 2) {
                dfs(result * a[aIdx], aIdx + 1);
            } else {
                dfs(result / a[aIdx], aIdx + 1);
            }

            op[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    dfs(a[0], 1);

    cout << maxResult << "\n" << minResult;

    return 0;
}