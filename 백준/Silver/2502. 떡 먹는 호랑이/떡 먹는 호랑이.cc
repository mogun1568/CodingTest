#include <iostream>

using namespace std;

int dp[31][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;

    dp[1][0] = 1;
    dp[2][1] = 1;
    for (int i = 3; i <= a; i++) {
        dp[i][0] = dp[i - 2][0] + dp[i - 1][0];
        dp[i][1] = dp[i - 2][1] + dp[i - 1][1];
    }

    for (int i = 1; i <= 100000; i++) {
        int c = b - dp[a][0] * i;
        if (c % dp[a][1] == 0) {
            cout << i << "\n" << c / dp[a][1];
            break;
        } 
    }
    
    return 0;
}