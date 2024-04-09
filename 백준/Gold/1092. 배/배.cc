#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, a, cnt = 0;
    vector<int> crane, box;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        crane.push_back(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        box.push_back(a);
    }

    sort(crane.begin(), crane.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());

    if (crane[0] < box[0]) {
        cout << -1;
        return 0;
    }
    
    while (!box.empty()) {
        cnt++;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < box.size(); j++) {
                if (crane[i] >= box[j]) {
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }

    cout << cnt;
    
    return 0;
}