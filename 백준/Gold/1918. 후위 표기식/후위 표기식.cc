#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> st;
    for (auto s : str) {
        if (s == '+' || s == '-') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.push(s);
        }
        else if (s == '*' || s == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }
            st.push(s);
        }
        else if (s == '(')
            st.push(s);
        else if (s == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else
            cout << s;
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    
    return 0;
}