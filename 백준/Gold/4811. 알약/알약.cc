#include <iostream>

using namespace std;

long long dp[31][31];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i <= 30; i++) {
        dp[0][i] = 1;
    }
    
    for (int w = 1; w <= 30; w++) {
        for (int h = 0; h <= 30; h++) {
            if (h == 0) {
                dp[w][h] = dp[w - 1][h + 1];
            } else {
                dp[w][h] = dp[w - 1][h + 1] + dp[w][h - 1];
            }
        }
    }
    
    int p;
    while (true) {
        cin >> p;
        if (p == 0) {
            break;
        }
        
        cout << dp[p][0] << "\n";
    }
    
    return 0;
}