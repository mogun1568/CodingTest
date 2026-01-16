#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, ans;
    cin >> N;
    ans = N;
    
    for (ll i = 2; i * i <= N; i++) {
        if (N % i == 0)
            ans -= ans / i;

        while (N % i == 0)
            N /= i;
    }
    
    if (N > 1)
        ans -= ans / N;

    cout << ans;
    
    return 0;
}