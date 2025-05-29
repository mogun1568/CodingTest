#include <iostream>
using namespace std;
#define MOD 10007

int DP[1001][10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < 10; i++)
        DP[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                DP[i][j] = 1;
                continue;
            }

            DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % MOD;
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum = (sum + DP[N][i]) % MOD;

    cout << sum;
    
    return 0;
}