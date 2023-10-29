#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int n;
    cin >> s >> n;

    stack<char> left, right;
    for (int i = 0; i < s.length(); i++) {
        left.push(s[i]);
    }

    char od, c;
    for (int i = 0; i < n; i++) {
        cin >> od;

        if (od == 'L') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } else if (od == 'D') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if (od == 'B') {
            if (!left.empty()) {
                left.pop();
            }
        } else {
            cin >> c;

            left.push(c);
        }
    }

    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }

    return 0;
}