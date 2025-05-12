#include <iostream>
#include <string>
using namespace std;

int arr[64][64];

void DFS(int r, int c, int n) {
    int temp = arr[r][c];
    bool check = false;

    for (int i = r; i < r + n; i++) {
        for (int j = c; j < c + n; j++) {
            if (arr[i][j] != temp) {
                check = true;
                cout << '(';

                n /= 2;
                DFS(r, c, n);
                DFS(r, c + n, n);
                DFS(r + n, c, n);
                DFS(r + n, c + n, n);

                cout << ')';
                break;
            }
        }

        if (check)
            break;
    }

    if (!check)
        cout << temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++)
            arr[i][j] = s[j] - '0';
    }

    DFS(0, 0, N);
    
    return 0;
}