#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int l, c;
string s;

void dfs(string pw, int idx, int consonant, int vowel) {
    if (idx == c) {
        if (pw.length() != l) {
            return;
        }

        if (consonant < 2 || vowel < 1) {
            return;
        }

        cout << pw << "\n";

        return;
    }

    if (s[idx] == 'a' || s[idx] == 'e' || s[idx] == 'i' || s[idx] == 'o' || s[idx] == 'u') {
        dfs(pw + s[idx], idx + 1, consonant, vowel + 1);
    } else {
       dfs(pw + s[idx], idx + 1, consonant + 1, vowel);
    }
    dfs(pw, idx + 1, consonant, vowel);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> l >> c;

    char a;
    for (int i = 0; i < c; i++) {
        cin >> a;
        s += a;
    }
    sort(s.begin(), s.end());

    dfs("", 0, 0, 0);
    
    return 0;
}