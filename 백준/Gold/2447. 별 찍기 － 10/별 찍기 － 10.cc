#include <iostream>
using namespace std;

void PrintStar(int i, int j) {
    while (i > 0 || j > 0) {
        if (i % 3 == 1 && j % 3 == 1) {
            cout << ' ';
            return;
        }

        i /= 3;
        j /= 3;
    }

    cout << '*';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            PrintStar(i, j);
        cout << "\n";
    }
    
    return 0;
}