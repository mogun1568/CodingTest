#include <iostream>

using namespace std;

bool arr[6561][6561];

int dr[7] = {0, 0, 1, 1, 2, 2, 2};
int dc[7] = {1, 2, 0, 2, 0, 1, 2};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a = 1;
    cin >> n;

    arr[0][0] = true;

    while (a != n) {
        for (int i = 0; i < 7; i++) {
            int sr = dr[i] * a;
            int sc = dc[i] * a;
            
            for (int j = sr; j < sr + a; j++) {
                for (int k = sc; k < sc + a; k++) {
                    arr[j][k] = arr[j - sr][k - sc];
                }
            }
        }

        a *= 3;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j]) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << "\n";
    }
    
    return 0;
}