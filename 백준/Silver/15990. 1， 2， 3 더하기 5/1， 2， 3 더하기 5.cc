#include <iostream>
using namespace std;
#define DIV 1000000009

int DP[100001][4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    DP[1][1] = 1;
    DP[2][2] = 1;

    DP[3][1] = 1; 
    DP[3][2] = 1; 
    DP[3][3] = 1;

    for (int i = 4; i < 100001; i++) {
        DP[i][1] = (DP[i - 1][2] + DP[i - 1][3]) % DIV;
        DP[i][2] = (DP[i - 2][1] + DP[i - 2][3]) % DIV;
        DP[i][3] = (DP[i - 3][1] + DP[i - 3][2]) % DIV;
    }
    
    int T;
    cin >> T;

    while (T--) {      
        int n;
        cin >> n;

        int ans = ((DP[n][1] + DP[n][2]) % DIV + DP[n][3]) % DIV;
        cout << ans << "\n";
    }
    
    return 0;
}