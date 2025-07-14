#include <iostream>
using namespace std;

int DP[31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    DP[0] = 1;
    DP[1] = 0;
    DP[2] = 3;

    for (int i = 3; i <= N; i++) {
        if (i % 2 == 0) {
            for (int j = 2; j <= i; j += 2)
                if (j == 2)
                    DP[i] = DP[i - j] * DP[2];
                else
                    DP[i] += DP[i - j] * 2;
        }
    }
    
    cout << DP[N];

    return 0;
}