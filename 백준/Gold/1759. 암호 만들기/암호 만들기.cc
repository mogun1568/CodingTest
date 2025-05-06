#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
string s;

void DFS(string pw, int idx, int consonant, int vowel) {
    if (pw.length() == L) {
        if (consonant > 1 && vowel > 0)
            cout << pw << "\n";
        
        return;    
    }

    for (int i = idx; i < C; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            DFS(pw + s[i], i + 1, consonant, vowel + 1);
        else
            DFS(pw + s[i], i + 1, consonant + 1, vowel);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;

    char c;
    for (int i = 0; i < C; i++) {
        cin >> c;
        s += c;
    }

    sort(s.begin(), s.end());

    DFS("", 0, 0, 0);
    
    return 0;
}