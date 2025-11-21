#include <iostream>
#include <algorithm>
using namespace std;

int DP[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int W, V;
    while(N--) {
        cin >> W >> V;
        for (int j = K; j >= W; j--)
            DP[j] = max(DP[j], DP[j - W] + V);
    }

    cout << DP[K];
    
    return 0;
}