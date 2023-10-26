#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string stick;
    cin >> stick;

    int result = 0, s = 0;
    for (int i = 0; i < stick.length(); i++) {
        if (stick[i] == '(') {
            if (stick[i + 1] == ')') {
                result += s;
                i++;
            } else {
                result++;
                s++;
            }
        } else {
            s--;
        }
    }

    cout << result;

    return 0;
}