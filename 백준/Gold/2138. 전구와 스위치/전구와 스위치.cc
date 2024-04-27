#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 987654321

int n, answer = MAX;
string ss, es, s;

void SwitchClick(int idx) {
    s[idx - 1] = (s[idx - 1] == '0') ? '1' : '0';
    s[idx] = (s[idx] == '0') ? '1' : '0';
    if (idx + 1 < n) {
        s[idx + 1] = (s[idx + 1] == '0') ? '1' : '0';
    }
}

void Solve(int def) {
    s = ss;
    int cnt = def;
    
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != es[i - 1]) {
            SwitchClick(i);
            cnt++;
        }

        if (s == es) {
            answer = min(answer, cnt);
            return;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> ss >> es;

    Solve(0);

    ss[0] = (ss[0] == '0') ? '1' : '0';
    ss[1] = (ss[1] == '0') ? '1' : '0';
    Solve(1);
    
    if (answer != MAX) {
        cout << answer;
    } else {
        cout << -1;
    }
    
    return 0;
}