#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int button[10];

bool check(int num) {
    string s = to_string(num);

    for (auto i : s) {
        if (button[i - '0']) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, b, save;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> b;
        button[b] = true;
    }

    save = abs(n - 100);
    for (int i = 0; i <= 1000000; i++) {
        if (check(i)) {
            int click = abs(i - n) + to_string(i).length();
            save = min(save, click);
        }
    }

    cout << save;

    return 0;
}