#include <iostream>

using namespace std;

int p[3][2];

int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; i++) {
        cin >> p[i][0] >> p[i][1];
    }

    int result = CCW(p[0][0], p[0][1], p[1][0], p[1][1], p[2][0], p[2][1]);

    if (result > 0) {
        cout << 1;
    } else if (result == 0) {
        cout << 0;
    } else {
        cout << -1;
    }

    return 0;
}