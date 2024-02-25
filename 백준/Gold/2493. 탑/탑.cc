#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    cin >> n;

    stack<pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
        cin >> h;

        while (!s.empty() && s.top().first <= h) {
            s.pop();
        }

        if (s.empty()) {
            cout << "0 ";
        } else {
            cout << s.top().second << ' ';
        }      
    
        s.push({h, i});
    }

    return 0;
}