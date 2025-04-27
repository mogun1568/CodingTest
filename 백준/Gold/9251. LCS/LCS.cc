#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LCS[1001][1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int len1 = s1.length(), len2 = s2.length();
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    cout << LCS[len1][len2];
    
    return 0;
}