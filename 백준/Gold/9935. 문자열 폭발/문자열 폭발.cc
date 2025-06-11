#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, bomb;
    cin >> s >> bomb;

    vector<char> ans;
    int bLen = bomb.length();
    bool check;
    
    for (int i = 0; i < s.length(); i++) {
        ans.push_back(s[i]);

        if (ans.size() >= bLen) {
            check = true;
            for (int j = 0; j < bLen; j++) {
                if (ans[ans.size() - bLen + j] != bomb[j]) {
                    check = false;
                    break;
                }
            }
            
            if (check) {
                for (int j = 0; j < bLen; j++)
                    ans.pop_back();
            }
        }
    }

    if (ans.empty())
        cout << "FRULA";
    else {
        for (char c : ans)
            cout << c;
    }

    return 0;
}
