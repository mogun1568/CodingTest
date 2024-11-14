#include <iostream>
#include <cctype>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, ans = "";
    bool isJava = false, isCpp = false;
    
    cin >> s;

    if (isupper(s.front()) || s.front() == '_' || s.back() == '_') {
        cout << "Error!";
        return 0;
    }

    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i])) {
            isJava = true;
            ans += '_';
            ans += tolower(s[i]);
        }
        else if (s[i] == '_') {
            if (s[i + 1] == '_' || isupper(s[i + 1])) {
                cout << "Error!";
                return 0;
            }
            
            isCpp = true;
            ans += toupper(s[++i]);
        }
        else
            ans += s[i];
    }

    if (isJava && isCpp) {
        cout << "Error!";
        return 0;
    }

    cout << ans;
        
    return 0;
}