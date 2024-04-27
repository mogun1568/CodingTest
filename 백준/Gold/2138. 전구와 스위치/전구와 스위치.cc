#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int n, answer;
string es;

string SwitchClick(string s, int idx) {
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

int Solve(string s, int def) {
    int cnt = def;
    
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != es[i - 1]) {
            s = SwitchClick(s, i);
            cnt++;
        }

        if (s == es) {
            return cnt;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string ss;
    cin >> n >> ss >> es;

    int answer = -1, temp1, temp2;
    temp1 = Solve(ss, 0);
    if (temp1 >= 0) {
        answer = temp1;
    }

    for (int i = 0; i < 2; i++) {
        if (ss[i] == '0') {
            ss[i] = '1';
        } else {
            ss[i] = '0';
        }
    }
    temp2 = Solve(ss, 1);
    if (temp2 >= 0) {
        if (answer >= 0) {
            answer = min(answer, temp2);
        } else {
            answer = temp2;
        }
    }
    
    cout << answer;
    
    return 0;
}