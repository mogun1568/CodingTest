#include <iostream>
using namespace std;

int DP[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, v;
    cin >> n >> k;

    DP[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> v;

        for (int j = v; j <= k; j++) {
            DP[j] += DP[j - v];
        }
    }

    cout << DP[k];
    
    return 0;
}