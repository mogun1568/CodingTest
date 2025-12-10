#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 10001;

vector<int> v[MAX];
int inDgree[MAX];
int workTime[MAX];
int DP[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int a, b, c;
    for (int i = 1; i <= N; i++) {
        cin >> a >> b;
        workTime[i] = DP[i] = a;

        while (b--) {
            cin >> c;
            v[c].push_back(i);
            inDgree[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDgree[i] == 0)
            q.push(i);
    }

    int ans = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        ans = max(ans, DP[cur]);

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            DP[next] = max(DP[next], DP[cur] + workTime[next]);

            if (--inDgree[next] == 0)
                q.push(next);
        }
    }

    cout << ans;
    
    return 0;
}