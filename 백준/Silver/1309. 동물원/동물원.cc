#include <iostream>
using namespace std;
#define MOD 9901

int DP[100001] = {1, 3};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 2; i <= N; i++) {
        DP[i] = 2 * DP[i - 1] + DP[i - 2];
        DP[i] %= MOD;
    }

    cout << DP[N];

    return 0;
}