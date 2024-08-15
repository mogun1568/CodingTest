#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[50];
long long dp[50];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    dp[0] = arr[0];
    dp[1] = max(dp[0] + arr[1], dp[0] * arr[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = max(dp[i - 1] + arr[i], dp[i - 2] + arr[i - 1] * arr[i]);
    }

    cout << dp[N - 1];
    
    return 0;
}