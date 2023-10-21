#include <iostream>

using namespace std;

bool haveMakerNum[10000];

int main()
{
    for (int i = 1; i < 10000; i++) {
        int n = i, sum = i;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        if (sum >= 10000) {
            continue;
        }

        haveMakerNum[sum] = true;
    }

    for (int i = 1; i < 10000; i++) {
        if (!haveMakerNum[i]) {
            cout << i << endl;
        }
    }

    return 0;
}