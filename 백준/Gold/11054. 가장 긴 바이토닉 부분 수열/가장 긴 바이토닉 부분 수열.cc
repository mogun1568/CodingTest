#include <iostream>
#include <algorithm>

using namespace std;

int N, answer;
int arr[1000];
int dp[1000][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        dp[i][0] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] > arr[j]) {
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            }
        }
    }
    
    for (int i = N - 1; i >= 0; i--) {
        dp[i][1] = 1;
        for (int j = i + 1; j < N; j++) {
            if (arr[i] > arr[j]) {
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
            }
        }

        answer = max(answer, dp[i][0] + dp[i][1] - 1);
    }

    cout << answer;

    return 0;
}