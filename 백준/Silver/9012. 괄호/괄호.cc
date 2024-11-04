#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool VPS(string s) {
    stack<char> st;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            st.push(s[i]);
        else {
            if (st.empty()) 
                return false;
            else {
                st.pop();
            }
        }
    }

    if (st.empty())
        return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        if (VPS(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}