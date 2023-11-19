#include <iostream>

using namespace std;

int arr[64][64];

void dfs(int r, int c, int n) {
    int t = arr[r][c];
    bool check = true;

    for (int i = r; i < r + n; i++) {
        for (int j = c; j < c + n; j++) {
            if (arr[i][j] != t) {
                check = false;
                cout << "(";
                
                n /= 2;
                dfs(r, c, n);
                dfs(r, c + n, n);
                dfs(r + n, c, n);
                dfs(r + n, c + n, n);

                cout << ")";
                break;
            }
        }

        if (!check) {
            break;
        }
    }
    
    if (check) {
        cout << t;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    dfs(0, 0, n);
    
    return 0;
}