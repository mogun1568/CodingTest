#include <iostream>

using namespace std;

#define MAX 1000001

int pNum[MAX];

void prime() {
    for (int i = 2; i * i < MAX; i++) {
        if (!pNum[i]) {
            for (int j = i * i; j < MAX; j += i) {
                pNum[j] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prime();

    int n;

    while (1) {
        cin >> n;

        if (n == 0) {
            break;
        }

        bool check = false;
        for (int i = 3; i <= n / 2; i += 2) {
            if (!pNum[i] && !pNum[n - i]) {
                check = true;
                cout << n << " = " << i << " + " << n - i << "\n";
                break;
            }
        }

        if (!check) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}