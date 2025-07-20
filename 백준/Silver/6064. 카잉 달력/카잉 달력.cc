#include <iostream>
using namespace std;

int GCD(int x, int y) {
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }

    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int LCM = M / GCD(M, N) * N;
        bool check = false;

        while (x != y) {
            if (x > LCM || y > LCM) {
                check = true;
                break;
            }

            if (x < y)
                x += M;
            else
                y += N;
        }

        if (check)
            cout << -1 << "\n";
        else
            cout << x << "\n";
    }
    
    return 0;
}