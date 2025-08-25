#include <iostream>
#include <string>
#include <stack>
using namespace std;

string Solve(string str) {
    stack<char> st;
    for (auto s : str) {
        if (s == '(' || s == '[')
            st.push(s);
        else if (s == ')') {
            if (st.empty() || st.top() != '(')
                return "no";
            st.pop();
        }
        else if (s == ']') {
            if (st.empty() || st.top() != '[')
                return "no";
            st.pop();
        }
    }

    if (!st.empty())
        return "no";

    return "yes";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    while (true) {
        getline(cin, str);
        
        if (str == ".")
            break;

        cout << Solve(str) << "\n";
    }
    
    return 0;
}