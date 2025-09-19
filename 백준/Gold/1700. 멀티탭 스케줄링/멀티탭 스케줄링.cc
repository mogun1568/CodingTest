#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool useMulti[101];
queue<int> whenUse[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> appliance;
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        appliance.push_back(a);
        whenUse[a].push(i);
    }

    int ans = 0;
    vector<int> multi;
    for (int i = 0; i < K; i++) {
        if (useMulti[appliance[i]]) {
            whenUse[appliance[i]].pop();
            continue;
        }
        
        if (multi.size() < N) {
            multi.push_back(appliance[i]);
            useMulti[appliance[i]] = true;
            whenUse[appliance[i]].pop();
            continue;
        }

        int idx = 0, a = 0;
        for (int j = 0; j < N; j++) {
            if (whenUse[multi[j]].empty()) {
                a = j;
                break;
            }
            else if (whenUse[multi[j]].front() > idx) {
                idx = whenUse[multi[j]].front();
                a = j;
            }
        }

        useMulti[multi[a]] = false;
        multi[a] = appliance[i];
        useMulti[multi[a]] = true;
        whenUse[multi[a]].pop();

        ans++;
    }

    cout << ans;
    
    return 0;
}