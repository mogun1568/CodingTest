#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10001

int DP[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K, c;
    cin >> N >> K;

    for (int i = 1; i <= K; i++)
        DP[i] = MAX;

    while (N--) {
        cin >> c;

        for (int i = c; i <= K; i++)
            DP[i] = min(DP[i], DP[i - c] + 1);
    }

    if (DP[K] == MAX)
        cout << -1;
    else
        cout << DP[K];
    
    return 0;
}