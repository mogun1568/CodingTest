#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        
    cin >> t;
    while (t--) {
        cin >> n;

        vector<string> v;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());

        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            string cur = v[i];
            string next = v[i + 1];

            if (cur.length() > next.length())
                continue;

            if (cur == next.substr(0, cur.length())) {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    
    return 0;
}