#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v[10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int k, cnt, b, deep;
    cin >> k;

    cnt = pow(2, k) - 1;
    deep = k - 1;
    
    for (int i = 0; i < cnt; i++) {
        cin >> b;

        if (i % 2 == 0) {
            deep = k - 1;
            v[deep].push_back(b);
        } else {
            deep--;
            while (v[deep].size() >= (v[deep + 1].size() + 1) / 2) {
                deep--;
            }
            v[deep].push_back(b);
        }
    }

    for (int i = 0; i < k; i++) {
        for (auto a : v[i]) {
            cout << a << " ";
        }
        cout << "\n";
    }
    
    return 0;
}