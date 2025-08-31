#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, ans;
vector<pair<int, int>> lan[50];
bool visited[50];

bool BFS() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int cCpt = pq.top().second;
        int cLen = pq.top().first;
        pq.pop();

        if (visited[cCpt])
            continue;
        visited[cCpt] = true;

        N--;
        ans -= cLen;

        for (int i = 0; i < lan[cCpt].size(); i++) {
            int nCpt = lan[cCpt][i].first;
            int nLen = lan[cCpt][i].second;

            if (visited[nCpt])
                continue;

            pq.push({nLen, nCpt});
        }
    }

    if (N == 0)
        return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            int len;
            if (str[j] >= 'a')
                len = str[j] - 96;
            else if (str[j] >= 'A')
                len = str[j] - 38;
            else
                continue;
            
            lan[i].push_back({j, len});
            lan[j].push_back({i, len});
            ans += len;
        }
    }

    if (BFS())
        cout << ans;
    else
        cout << -1;
    
    return 0;
}