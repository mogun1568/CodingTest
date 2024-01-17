#include <iostream>

using namespace std;

int n, maxEnergy = 0;
int bead[10];
bool check[10];

void dfs(int cnt, int energy) {
    if (cnt <= 2) {
        maxEnergy = max(maxEnergy, energy);
        return;
    }
    
    for (int i = 1; i < n - 1; i++) {
        if (check[i]) {
            continue;
        }

        int j = 1, k = 1;
        while (check[i - j]) {
            j++;
        }
        while (check[i + k]) {
            k++;
        }

        check[i] = true;
        dfs(cnt - 1, energy + bead[i - j] * bead[i + k]);
        check[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> bead[i];
    }

    dfs(n, 0);

    cout << maxEnergy;
    
    return 0;
}