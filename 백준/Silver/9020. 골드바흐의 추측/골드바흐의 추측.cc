#include <iostream>

using namespace std;

int prime[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 2; i < 10001; i++) {
        if (prime[i]) {
            continue;
        }
        
        for (int j = i + i; j < 10001; j += i) {
            prime[j] = true;
        }
    }

    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        for (int j = n / 2; j >= 2; j--) {
            if (!prime[j] && !prime[n - j]) {
                cout << j << ' ' << n - j << "\n";
                break;
            }
        }
    }
    
    return 0;
}