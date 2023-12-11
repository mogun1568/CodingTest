#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, cnt = 0;
    string s;
    cin >> n >> m >> s;


    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == 'O') {
            continue;
        }

        k = 0;
        while (s[i + 1] == 'O' && s[i + 2] == 'I') {
            k++;
            if (k == n) {
                cnt++;
                k--;
            }

            i += 2;
        }
    }

    cout << cnt;

    return 0;
}