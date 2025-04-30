#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int M, chickenCnt, ans = 10000;
vector<pair<int, int>> house, chicken;
bool ischicken[13];

void DFS(int idx, int cnt) {
    if (cnt == M) {
        int sum = 0, dis;
        for (auto h : house) {
            dis = 100;
            for (int i = 0; i < chickenCnt; i++) {
                if (!ischicken[i])
                    continue;

                dis = min(dis, abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second));
            }

            sum += dis;
        }

        ans = min(ans, sum);
        
        return;
    }

    for (int i = idx; i < chickenCnt; i++) {
        ischicken[i] = true;
        DFS(i + 1, cnt + 1);
        ischicken[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, a;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a;

            if (a == 1)
                house.push_back({i, j});
            else if (a == 2)
                chicken.push_back({i, j});
        }
    }
    chickenCnt = chicken.size();

    DFS(0, 0);

    cout << ans;
    
    return 0;
}