#include <iostream>
#include <string>
#include <stack>

using namespace std;

string S;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S;

    stack<int> st;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '(') {
            st.push(-1);
        } else if (S[i] == ')') {
            int temp = 0;
            
            while (st.top() != -1) {
                temp += st.top();
                st.pop();
            }
            st.pop();

            temp *= st.top();
            st.pop();
            st.push(temp);
        } else {
            if (S[i + 1] == '(') {
                st.push(S[i] - '0');
            } else {
                st.push(1);
            }
        }
    }

    int answer = 0;
    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }

    cout << answer;
    
    return 0;
}