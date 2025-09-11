#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arrA[1000], arrB[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, m;
    cin >> T >> n;

    vector<int> sumA, sumB;
    for (int i = 0; i < n; i++) {
        cin >> arrA[i];

        int sum = 0;
        for (int j = i; j >= 0; j--) {
            sum += arrA[j];
            sumA.push_back(sum);
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arrB[i];

        int sum = 0;
        for (int j = i; j >= 0; j--) {
            sum += arrB[j];
            sumB.push_back(sum);
        }
    }

    long long ans = 0;
    sort(sumB.begin(), sumB.end());
    for (const int& sum : sumA) {
        auto ub = upper_bound(sumB.begin(), sumB.end(), T - sum);
		auto lb = lower_bound(sumB.begin(), sumB.end(), T - sum);
		ans += ub - lb;
    }

    cout << ans;
    
    return 0;
}