#include <iostream>
#include <algorithm>
using namespace std;

int children[200];
int DP[200];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, LIS = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> children[i];
        DP[i] = 1;

        for (int j = i - 1; j >= 0; j--) {
            if (children[j] < children[i])
                DP[i] = max(DP[i], DP[j] + 1);
        }

        LIS = max(LIS, DP[i]);
    }

    cout << N - LIS;
    
    return 0;
}