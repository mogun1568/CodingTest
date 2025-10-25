#include <iostream>
#include <algorithm>
using namespace std;

int warehouse[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, L, H;
    cin >> N;

    int maxH = 0, pL = 0, pR = 0;
    for (int i = 0; i < N; i++) {
        cin >> L >> H;
        warehouse[L] = H;

        if (H > maxH) {
            maxH = H;
            pL = L;
        }
        if (H == maxH)
            pR = L + 1;
    }

    int ans = (pR - pL) * maxH;

    int lH = 0, rH = 0;
    for (int i = 1; i < pL; i++) {
        lH = max(lH, warehouse[i]);
        ans += lH;
    }
    for (int i = 1000; i >= pR; i--) {
        rH = max(rH, warehouse[i]);
        ans += rH;
    }

    cout << ans;
    
    return 0;
}