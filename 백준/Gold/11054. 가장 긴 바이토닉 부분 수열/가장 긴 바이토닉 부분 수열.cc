#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int DP[1000][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, ans = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        DP[i][0] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j])
                DP[i][0] = max(DP[i][0], DP[j][0] + 1);
        }
    }
    
    for (int i = N - 1; i >= 0; i--) {
        DP[i][1] = 1;
        for (int j = i + 1; j < N; j++) {
            if (arr[i] > arr[j])
                DP[i][1] = max(DP[i][1], DP[j][1] + 1);
        }

        ans = max(ans, DP[i][0] + DP[i][1] - 1);
    }

    cout << ans;

    return 0;
}