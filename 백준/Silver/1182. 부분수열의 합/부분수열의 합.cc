#include <iostream>

using namespace std;

int n, s, cnt = 0;

int arr[20];

void dfs(int i, bool use, int sum) {
    if (use) {
        sum += arr[i];
    }

    if (i == n - 1) {
        if (sum == s) {
            cnt++;
        }
        return;
    }

    dfs(i + 1, true, sum);
    dfs(i + 1, false, sum);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dfs(0, true, 0);
    dfs(0, false, 0);

    if (s == 0) {
        cnt--;
    }

    cout << cnt;

    return 0;
}