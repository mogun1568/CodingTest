#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPal[2501][2501];
int DP[2501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int len = str.length();
    str = " " + str;

    // 길이 1
    for (int i = 1; i <= len; i++)
        isPal[i][i] = true;

    // 길이 2
    for (int i = 1; i < len; i++) {
        if (str[i] == str[i + 1])
            isPal[i][i + 1] = true;
    }

    // 길이 3 이상 (i == 간격)
    for (int i = 2; i < len; i++) {
        for (int j = 1; j <= len - i; j++) {
            if (str[j] == str[j + i] && isPal[j + 1][j + i - 1])
                isPal[j][j + i] = true;
        }
    }

    for (int end = 1; end <= len; end++) {
        DP[end] = 2e9;
        for (int start = 1; start <= end; start++) {
            if (isPal[start][end])
                DP[end] = min(DP[end], DP[start - 1] + 1);
        }
    }

    cout << DP[len];
    
    return 0;
}