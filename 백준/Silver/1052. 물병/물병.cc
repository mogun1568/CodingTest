#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    for (int i = 23; i >= 0; i--) {
        int tmp = pow(2, i);
        
        if (n - tmp >= 0) {
            n -= tmp;
            k--;
        }

        if (n == 0) {
            cout << 0;
            return 0;
        }
        
        if (k <= 0) {
            cout << tmp - n;
            return 0;
        }
    }
    
    return 0;
}