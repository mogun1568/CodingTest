#include <iostream>
#include <map>
#include <queue>

using namespace std;

int T, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    while (T--) {
        cin >> k;

        map<int, int> m;
        priority_queue<int> hpq;
        priority_queue<int, vector<int>, greater<int>> lpq;

        char c;
        int n;
        while (k--) {
            cin >> c >> n;

            if (c == 'I') {
                m[n]++;
                hpq.push(n);
                lpq.push(n);
            }
            else {
                if (n == 1) {
                    if (!hpq.empty()) {
                        m[hpq.top()]--;
                        hpq.pop();
                    }
                }
                else {
                    if (!lpq.empty()) {
                        m[lpq.top()]--;
                        lpq.pop();
                    }
                }

                while (!hpq.empty() && m[hpq.top()] == 0)
                    hpq.pop();
                while (!lpq.empty() && m[lpq.top()] == 0)
                    lpq.pop();
            }
        }

        if (hpq.empty() || lpq.empty())
            cout << "EMPTY\n";
        else
            cout << hpq.top() << " " << lpq.top() << "\n";
    }
    
    return 0;
}