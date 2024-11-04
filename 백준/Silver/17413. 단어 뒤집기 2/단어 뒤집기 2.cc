#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> st;

void PrintStack() {
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    bool tag = false;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '<') {
            PrintStack();
            tag = true;
            cout << s[i];
            continue;
        }
        else if (s[i] == '>') {
            tag = false;
            cout << s[i];
            continue;
        }

        if (tag)
            cout << s[i];
        else {
            if (s[i] == ' ') {
                PrintStack();
                cout << s[i];
            }
            else
                st.push(s[i]);
        }
    }
    PrintStack();
    
    return 0;
}