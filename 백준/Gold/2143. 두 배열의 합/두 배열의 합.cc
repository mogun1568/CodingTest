#include <iostream>
#include <unordered_map>
using namespace std;

int arrA[1000], arrB[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, m;
    cin >> T >> n;

    unordered_map<int, int> um;
    for (int i = 0; i < n; i++) {
        cin >> arrA[i];

        int sum = 0;
        for (int j = i; j >= 0; j--) {
            sum += arrA[j];
            um[sum]++;
        }
    }

    long long ans = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arrB[i];

        int sum = 0;
        for (int j = i; j >= 0; j--) {
            sum += arrB[j];
            ans += um[T - sum];
        }
    }

    cout << ans;
    
    return 0;
}