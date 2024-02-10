#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int m, chiLen, result = 20000;
vector<pair<int, int>> house, chicken;
bool checkChi[13];

void dfs(int cnt, int idx) {
    if (chiLen - cnt == m) {
        int sum = 0;
        for (auto h : house) {
            int dis = 110;
            for (int i = 0; i < chiLen; i++) {
                if (checkChi[i]) {
                    continue;
                }
                                
                dis = min(dis, abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second));
            }
    
            sum += dis;
        }

        result = min(result, sum);
        
        return;
    }

    for (int i = idx; i < chiLen; i++) {
        checkChi[i] = true;
        dfs(cnt + 1, i + 1);
        checkChi[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;

            if (a == 1) {
                house.push_back({i, j});
            } else if (a == 2) {
                chicken.push_back({i, j});
            }
        }
    }
    chiLen = chicken.size();

    dfs(0, 0);

    cout << result;
    
    return 0;
}