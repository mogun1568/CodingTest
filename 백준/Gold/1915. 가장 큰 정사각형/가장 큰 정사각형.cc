#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
int arr[1001][1001];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = s[j - 1] - '0';
        }
    }

    int len = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 0)
                continue;
            
            arr[i][j] = min(min(arr[i - 1][j], arr[i][j - 1]), arr[i - 1][j - 1]) + 1;
            len = max(len, arr[i][j]);
        }
    }
    
    cout << len * len;
    
    return 0;
}