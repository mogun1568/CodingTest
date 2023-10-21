#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, result = 0;
    cin >> n;
    
    int arr[n], dp[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        result = max(result, dp[i]);
    }
    
    cout << result;

    return 0;
}