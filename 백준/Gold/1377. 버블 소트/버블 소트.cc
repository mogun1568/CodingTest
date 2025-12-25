#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> A;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        A.push_back({a, i});
    }

    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, A[i].second - i);

    cout << ans + 1;
    
    return 0;
}