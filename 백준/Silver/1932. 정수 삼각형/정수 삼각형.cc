#include <iostream>
#include <algorithm>

using namespace std;

int ta[500][500];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, result = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> ta[i][j];

            if (i > 0) {
                if (j == 0) {
                    ta[i][j] += ta[i - 1][j];
                } else if (j == i) {
                    ta[i][j] += ta[i - 1][j - 1];
                } else {
                    ta[i][j] += max(ta[i - 1][j - 1], ta[i - 1][j]);
                }
            }

            if (i == n - 1) {
                result = max(result, ta[i][j]);
            }
        }
    }

    cout << result;

    return 0;
}