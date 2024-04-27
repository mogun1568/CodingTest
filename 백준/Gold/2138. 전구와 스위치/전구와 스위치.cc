#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 987654321

int n, answer = MAX;
string ss, es, s;

string SwitchClick(int idx) {
    for (int i = idx - 1; i <= idx + 1; i++) {
        if (i >= n) {
            continue;
        }
        
        if (s[i] == '0') {
            s[i] = '1';
        } else {
            s[i] = '0';
        }
    }

    return s;
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

    for (int i = 0; i < 2; i++) {
        if (ss[i] == '0') {
            ss[i] = '1';
        } else {
            ss[i] = '0';
        }
    }
    Solve(1);
    
    if (answer != MAX) {
        cout << answer;
    } else {
        cout << -1;
    }
    
    return 0;
}