#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    string start = "", end, str;
    for (int i = 0; i < k; i++)
        start += 'A' + i;
    cin >> end;

    int qRow;
    vector<string> ladder;
    for (int i = 0; i < n; i++) {
        cin >> str;
        ladder.push_back(str);

        if (str[0] == '?')
            qRow = i;
    }

    for (int i = 0; i < qRow; i++) {
        for (int j = 0; j < k - 1; j++) {
            if (ladder[i][j] == '-')
                swap(start[j], start[j + 1]);
        }
    }

    for (int i = n - 1; i > qRow; i--) {
        for (int j = 0; j < k - 1; j++) {
            if (ladder[i][j] == '-')
                swap(end[j], end[j + 1]);
        }
    }

    string ans = "";
    bool flag = false;
    for (int i = 0; i < k - 1; i++) {
        if (start[i] == end[i])
            ans += '*';
        else if (start[i] == end[i + 1] || start[i + 1] == end[i]) {
            ans += '-';
            swap(start[i], start[i + 1]);
        }
        else {
            flag = true;
            break;
        }
    }

    if (flag) {
        for (int i = 0; i < k - 1; i++)
            cout << 'x';
    }
    else
        cout << ans;
    
    return 0;
}