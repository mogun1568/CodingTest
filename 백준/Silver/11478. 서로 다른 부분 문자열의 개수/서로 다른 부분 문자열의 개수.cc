#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    set<string> str;
    
    for (int i = 0; i < s.length(); i++) {
        for (int j = 1; j <= s.length(); j++)
            str.insert(s.substr(i, j));
    }

    cout << str.size();
    
    return 0;
}