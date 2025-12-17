#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int DP[1101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int C, N;
    cin >> C >> N;

    for (int i = 1; i <= C + 100; i++)
        DP[i] = INF;
    
    int cost, num;
    while (N--) {
        cin >> cost >> num;

        for (int i = num; i <= C + 100; i ++)
            DP[i] = min(DP[i], DP[i - num] + cost);
    }

    int ans = DP[C];
    for (int i = C + 1; i <= C + 100; i++)
        ans = min(ans, DP[i]);

    cout << ans;
    
    return 0;
}