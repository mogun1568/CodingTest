#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<stack<char>> v;

bool Solution(char cur) {
    char pre;
    if (cur == 'u') pre = 'q';
    else if (cur == 'a') pre = 'u';
    else if (cur == 'c') pre = 'a';
    else pre = 'c';

    bool flag = false;
    for (auto& i : v) {
        if (flag)
            break;

        if (i.empty())
            continue;

        if (i.top() == pre) {
            flag = true;
            i.push(cur);

            if (cur == 'k') {
                while(!i.empty())
                    i.pop();
            }
        }
    }

    if (flag)
        return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    stack<char> st;
    v.push_back(st);
    
    for (auto i : s) {
        if (i == 'q') {
            bool flag = false;
            for (auto& j : v) {
                if (j.empty()) {
                    flag = true;
                    j.push(i);
                    break;
                }
            }

            if (!flag) {
                v.push_back(st);
                v.back().push(i);
            }
        }
        else {
            if (!Solution(i)) {
                cout << -1;
                return 0;
            }
        }
    }

    for (auto i : v) {
        if (!i.empty()) {
            cout << -1;
            return 0;
        }
    }

    cout << v.size();
    
    return 0;
}