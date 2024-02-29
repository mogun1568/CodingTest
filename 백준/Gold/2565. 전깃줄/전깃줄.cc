#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, result = 0;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[j].second < v[i].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }

    cout << n - result;      

    return 0;
}