#include <iostream>

using namespace std;

int gcd(int x, int y) {
    int a = x, b = y, c = 0;

    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    return x * y / a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, m, n, x, y;
    cin >> t;

    while (t--) {
        cin >> m >> n >> x >> y;

        int maxV = gcd(m, n);
        bool check = false;

        while (x != y) {
            if (x > maxV || y > maxV) {
                check = true;
                break;
            }

            if (x < y) {
                x += m;
            } else {
                y += n;
            }
        }

        if (check) {
            cout << -1 << "\n";
        } else {
            cout << x << "\n";
        }   
    }

    return 0;
}