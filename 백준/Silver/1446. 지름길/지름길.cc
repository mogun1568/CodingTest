#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sc[12];
int dp[10001];

bool cmp(vector<int> &a, vector<int> &b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, d, a;
    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a;
            sc[i].push_back(a);
        }
    }

    sort(sc, sc + n, cmp);

    int j = 0;
    for (int i = 1; i <= d; i++) {
        dp[i] = dp[i - 1] + 1;

        while (j < n && sc[j][1] == i) {
            dp[i] = min(dp[i], dp[sc[j][0]] + sc[j][2]);
            j++;
        }
    }

    cout << dp[d];
    
    return 0;
}