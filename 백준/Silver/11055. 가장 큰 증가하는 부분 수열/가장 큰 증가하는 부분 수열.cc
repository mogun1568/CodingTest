#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000], dp[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, result = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];

        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }

        result = max(result, dp[i]);
    }

    cout << result;
    
    return 0;
}