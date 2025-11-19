#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

const int MOD = 900528;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string character, password;
    cin >> character >>  password;

    unordered_map<char, int> um;
    int len = character.length();
    for (int i = 0; i < len; i++)
        um[character[i]] = i + 1;

    int ans = 0, a = 1;
    for (int i = password.length() - 1; i >= 0; i--) {
        ans = (ans + um[password[i]] * a) % MOD;
        a = (a * len) % MOD;
    }

    cout << ans;
    
    return 0;
}