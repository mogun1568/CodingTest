#include <iostream>
#include <algorithm>

using namespace std;

int wine[10001];
int DP[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    cin >> wine[1] >> wine[2];

    DP[1] = wine[1];
    DP[2] = wine[1] + wine[2];

    for (int i = 3; i <= N; i++) {
        cin >> wine[i];

        DP[i] = max(DP[i - 3] + wine[i - 1] + wine[i], max(DP[i - 2] + wine[i], DP[i - 1]));
    }
    
    cout << DP[N];
    
    return 0;
}