#include <iostream>
#include <algorithm>
using namespace std;

int DP[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int workTime, workCnt, preNum, ans = 0;
    for (int i = 1; i <= N; i++) {
        cin >> workTime >> workCnt;

        int maxTime = 0;
        while (workCnt--) {
            cin >> preNum;
            maxTime = max(maxTime, DP[preNum]);
        }

        DP[i] = maxTime + workTime;
        ans = max(ans, DP[i]);
    }

    cout << ans;
    
    return 0;
}