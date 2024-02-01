#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    int t = 1, cnt;

    while (1) {
        cin >> s;

        if (s[0] == '-') {
            break;
        }

        cnt = 0;
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (st.empty()) {
                if (s[i] == '}') {
                    cnt++;
                }

                st.push('{');
            } else {
                if (s[i] == '}') {
                    st.pop();
                } else {
                    st.push('{');
                }
            }
        }

        cnt += st.size() / 2;

        cout << t << ". " << cnt << "\n";
        t++;
    }
    
    return 0;
}