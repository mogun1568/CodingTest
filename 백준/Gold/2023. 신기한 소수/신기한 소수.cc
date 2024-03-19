#include <iostream>
#include <cmath>

using namespace std;

int n;

void dfs(int num) {
    bool check = true;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            check = false;
        }
    }

    if (check) {
        if (num > pow(10, n - 1)) {
            cout << num << "\n";
            return;
        }

        dfs(10 * num + 1);
        dfs(10 * num + 3);
        dfs(10 * num + 7);
        dfs(10 * num + 9);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dfs(2);
    dfs(3);
    dfs(5);
    dfs(7);

    return 0;
}