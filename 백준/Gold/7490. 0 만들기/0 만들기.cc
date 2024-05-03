#include <iostream>
#include <string>

using namespace std;

int T, N;

void Dfs(string s, int cur, int sign, int value, int result) {
    if (cur == N) {
        if (result + sign * value == 0) {
            cout << s << "\n";
        }

        return;
    }

    Dfs(s + ' ' + to_string(cur + 1), cur + 1, sign, value * 10 + (cur + 1), result);
    Dfs(s + '+' + to_string(cur + 1), cur + 1, 1, cur + 1, result + sign * value);
    Dfs(s + '-' + to_string(cur + 1), cur + 1, -1, cur + 1, result + sign * value);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
        
    while (T--) {
        cin >> N;
        Dfs("1", 1, 1, 1, 0);
        cout << "\n";
    }
    
    return 0;
}