#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int ans = 0, sum = 1;
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push('(');
            sum *= 2;
        } else if (s[i] == '[') {
            st.push('[');
            sum *= 3;
        } else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                ans = 0;
                break;
            }
            if (s[i - 1] == '(') {
                st.pop();
                ans += sum;
                sum /= 2;
            } else {
                st.pop();
                sum /= 2;
            }
        } else {
            if (st.empty() || st.top() != '[') {
                ans = 0;
                break;
            }
            if (s[i - 1] == '[') {
                st.pop();
                ans += sum;
                sum /= 3;
            } else {
                st.pop();
                sum /= 3;
            }
        }
    }

    if (!st.empty())
        ans = 0;

    cout << ans;

    return 0;
}