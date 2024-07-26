#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[1000];
vector<int> dp[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    int len = 0, idx = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                if (dp[j].size() > dp[i].size()) {
                    dp[i] = dp[j];
                }
            }
        }
        dp[i].push_back(arr[i]);

        if (dp[i].size() > len) {
            len = dp[i].size();
            idx = i;
        }
    }

    cout << len << "\n";
    for (auto a : dp[idx])
        cout << a << " ";
    
    return 0;
}