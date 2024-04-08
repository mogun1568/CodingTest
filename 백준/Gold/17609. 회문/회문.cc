#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s;
int result;

void dfs(int i, int j, int cnt) {
    if (result < 2) {
        return;
    }
    
    if (cnt > 1) {
        return;
    }
    
    if (i >= j) {
        if (cnt < 2) {
            result = cnt;
        }
        return;
    }
    
    if (s[i] != s[j]) {
        dfs(i + 1, j, cnt + 1);
        dfs(i, j - 1, cnt + 1);
    } else {
        dfs(i + 1, j - 1, cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        cin >> s;

        result = 2;
        dfs(0, s.length() - 1, 0);

        cout << result << "\n";
    }
    
    return 0;
}