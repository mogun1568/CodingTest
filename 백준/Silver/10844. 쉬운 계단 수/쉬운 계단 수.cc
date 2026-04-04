#include <iostream>
using namespace std;

int const MOD = 1e9;

int stairs[101][10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i < 10; i++)
        stairs[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        stairs[i][0] = stairs[i - 1][1];
        stairs[i][9] = stairs[i - 1][8];
        for (int j = 1; j < 9; j++)
            stairs[i][j] = (stairs[i - 1][j - 1] + stairs[i - 1][j + 1]) % MOD;
    }

    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans = (ans + stairs[N][i]) % MOD;

    cout << ans;
    
    return 0;
}