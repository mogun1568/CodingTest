#include <iostream>
using namespace std;
#define DIV 1000000000

int DP[101][10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i < 10; i++)
        DP[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0)
                DP[i][j] = DP[i - 1][1] % DIV;
            else if (j == 9)
                DP[i][j] = DP[i - 1][8] % DIV;
            else
                DP[i][j] = (DP[i - 1][j - 1] % DIV + DP[i - 1][j + 1] % DIV) % DIV;
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum = (sum + DP[N][i]) % DIV;

    cout << sum;
    
    return 0;
}