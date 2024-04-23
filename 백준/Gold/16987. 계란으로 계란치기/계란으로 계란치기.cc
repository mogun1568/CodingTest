#include <iostream>
#include <algorithm>

using namespace std;

int n, maxEgg;
int eggs[8][2];

void Dfs(int idx) {
    if (idx >= n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (eggs[i][0] <= 0) {
                cnt ++;
            }
        }
        maxEgg = max(maxEgg, cnt);
        return;
    }
    
    
    if (eggs[idx][0] <= 0) {
        Dfs(idx + 1);       
        return;
    }

    bool check = false;
    for (int i = 0; i < n; i++) {
        if (idx == i || eggs[i][0] <= 0) {
            continue;
        }
        
        eggs[idx][0] -= eggs[i][1];
        eggs[i][0] -= eggs[idx][1];
        check = true;
        Dfs(idx + 1);
        eggs[idx][0] += eggs[i][1];
        eggs[i][0] += eggs[idx][1];
    }

    if (!check) {
        Dfs(n);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> eggs[i][0] >> eggs[i][1];
    }

    Dfs(0);
    cout << maxEgg;
    
    return 0;
}