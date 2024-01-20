#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(string a, string b, string c) {
    int cnt = 0;
    
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
        if (a[i] != c[i]) {
            cnt++;
        }
        if (b[i] != c[i]) {
            cnt++;
        }
    }
    
    return cnt;
}

int solve(vector<string> v) {
    int result = 100;
    
    for (int i = 0; i < v.size() - 2; i++) {
        for (int j = i + 1; j < v.size() - 1; j++) {
            for (int k = j + 1; k < v.size(); k++) {
                result = min(result, check(v[i], v[j], v[k]));
            }
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        vector<string> mbti;
        string str;
        for (int i = 0; i < n; i++) {
            cin >> str;
            mbti.push_back(str);
        }

        if (n < 33) {
            cout << solve(mbti) << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}