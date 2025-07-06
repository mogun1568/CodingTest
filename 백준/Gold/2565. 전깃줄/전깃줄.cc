#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DP[100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, ans = 0;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        DP[i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[j].second < v[i].second)
                DP[i] = max(DP[i], DP[j] + 1);
        }
        ans = max(ans, DP[i]);
    }

    cout << n - ans;      

    return 0;
}