#include <iostream>
#include <cstring>

using namespace std;

int N;
char arr[3100][6200];

void Star(int n, int r, int c) {
    if (n == 3) {
        arr[r][c] = '*';
        arr[r + 1][c - 1] = '*';
        arr[r + 1][c + 1] = '*';
        for (int i = c - 2; i <= c + 2; i++) {
            arr[r + 2][i] = '*';
        }
    }
    else {
        Star(n / 2, r, c);
        Star(n / 2, r + n / 2, c - n / 2);
        Star(n / 2, r + n / 2, c + n / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    memset(arr, ' ', sizeof(arr));
    Star(N, 0, N - 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}