#include <iostream>
using namespace std;

bool grape[100][100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> grape[i][j];
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grape[i][k] && grape[k][j])
                    grape[i][j] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << grape[i][j] << " ";
        cout << "\n";
    }

    return 0;
}