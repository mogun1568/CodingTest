#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string l, r;
    cin >> l >> r;

    if (l.length() != r.length()) {
        cout << 0;
        return 0;
    }

    int cnt = 0;
    for (int j = 0; j < l.length(); j++) {
        if (l[j] != r[j]) {
            break;
        }

        if (l[j] == '8') {
            cnt++;
        }
    }

    cout << cnt;
    
    return 0;
}