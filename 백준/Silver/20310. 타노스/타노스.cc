#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int zero = 0, one = 0;
    for (auto s : str) {
        if (s == '0')
            zero++;
        else
            one++;
    }

    string ans = "";
    int curZero = 0, curOne = 0;
    for (auto s : str) {
        if (s == '0') {
            curZero++;

            if (curZero <= zero / 2)
                ans += '0';
        }
        else {
            curOne++;

            if (curOne > one / 2)
                ans += '1';
        }
    }

    cout << ans;
    
    return 0;
}