#include <iostream>
#include <string>
#include <stack>

using namespace std;

string S;
stack<char> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S;

    for (int i = 0; i < S.length(); i++) {     
        if (S[i] == '+' || S[i] == '-') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }

            st.push(S[i]);
        }
        else if (S[i] == '*' || S[i] == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }

            st.push(S[i]);
        }
        else if (S[i] == '(') {
            st.push(S[i]);
        }
        else if (S[i] == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            cout << S[i];
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    
    return 0;
}