#include <iostream>
#include <algorithm>
using namespace std;

int DP[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> DP[i];

        for (int j = 1; j <= i / 2; j++)
            DP[i] = max(DP[i], DP[j] + DP[i - j]);
    }

    cout << DP[N];
    
    return 0;
}