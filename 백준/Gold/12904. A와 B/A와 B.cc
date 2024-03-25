#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int sLen = s.length();
    while (true) {
        int tLen = t.length();

        if (tLen == sLen) {
            if (t == s) {
                cout << 1;
            } else {
                cout << 0;
            }

            return 0;
        }
        
        if (t[tLen - 1] == 'A') {
            t.erase(tLen - 1);
        } else {
            t.erase(tLen - 1);
            reverse(t.begin(), t.end());
        }
    }
    
    return 0;
}