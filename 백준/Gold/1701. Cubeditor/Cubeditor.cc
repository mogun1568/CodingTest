#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;
int ans;

vector<int> Fail(string p) {
    vector<int> pi(p.length(), 0);

    for (int i = 1, j = 0; i < p.length(); i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];

        if (p[i] == p[j])
            pi[i] = ++j;
    }

    return pi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        vector<int> pi = Fail(s.substr(i));

        for (int j = 0; j < s.length() - i; j++)
            ans = max(ans, pi[j]);
    }

    cout << ans;
    
    return 0;
}