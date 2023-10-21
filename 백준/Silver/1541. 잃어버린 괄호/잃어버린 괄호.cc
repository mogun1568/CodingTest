#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    vector<string> v;
    string tmp = "";

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '+') {
            v.push_back(tmp);
            tmp = "";
        } else if (str[i] == '-') {
            v.push_back(tmp);
            v.push_back("-");
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    v.push_back(tmp);

    int result = 0, sign = 1;
    for (auto i : v) {
        if (i == "-") {
            sign = -1;
            continue;
        }

        result += sign * stoi(i);
    }

    cout << result;

    return 0;
}