#include <iostream>

using namespace std;

char arrA[50][50];
char arrB[50][50];

void changeArr(int n, int m) {
    for (int i = n; i < n + 3; i++) {
        for (int j = m; j < m + 3; j++) {
            if (arrA[i][j] == '0') {
                arrA[i][j] = '1';
            } else {
                arrA[i][j] = '0';
            }
        }
    }
}

bool check(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arrA[i][j] != arrB[i][j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arrA[i][j] = s[j];
        }
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arrB[i][j] = s[j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (arrA[i][j] != arrB[i][j]) {
                changeArr(i, j);
                cnt++;
            }
        }
    }

    if (check(n, m)) {
        cout << cnt;
    } else {
        cout << -1;
    }

    return 0;
}