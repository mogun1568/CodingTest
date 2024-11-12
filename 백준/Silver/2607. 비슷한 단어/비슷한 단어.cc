#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

int n, ans;
string s;
unordered_map<char, int> um;

bool Solution(string str) {
    unordered_map<char, int> tm;
    int cnt = s.length();
    int cnt2 = str.length();

    if (abs(cnt - cnt2) > 1)
        return false;

    for (auto i : str) {
        if (tm[i] < um[i]) {
            cnt--;
            cnt2--;
            tm[i]++;
        }
    }

    if (cnt < 2 && cnt2 < 2)
        return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (auto i : s)
        um[i]++;

    string str;
    for (int i = 1; i < n; i++) {
        cin >> str;

        if (Solution(str))
            ans++;
    }

    cout << ans;
    
    return 0;
}