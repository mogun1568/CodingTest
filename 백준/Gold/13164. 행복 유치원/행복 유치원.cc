#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ks[300000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> ks[i];
    }

    vector<int> dif;
    for (int i = 1; i < n; i++) {
        dif.push_back(ks[i] - ks[i - 1]);
    }
    sort(dif.begin(), dif.end());

    int answer = 0;
    for (int i = 0; i < dif.size() - (k - 1); i++) {
        answer += dif[i];
    }

    cout << answer;
    
    return 0;
}