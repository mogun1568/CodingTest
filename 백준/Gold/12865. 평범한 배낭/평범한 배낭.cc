#include <iostream>
#include <algorithm>
using namespace std;

int DP[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int W, V;
    while (N--) {
        cin >> W >> V;

        for (int i = K; i >= W; i--)
            DP[i] = max(DP[i], DP[i - W] + V);
    }

    cout << DP[K];
    
    return 0;
}