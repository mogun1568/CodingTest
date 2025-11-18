#include <iostream>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

const int MAX = 10000;

bool prime[MAX];
bool visited[MAX];

void GetPrime() {
    prime[0] = true;
    prime[1] = true;
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i])
            continue;

        for (int j = i * i; j < MAX; j += i)
            prime[j] = true;
    }
}

int BFS(int a, int b) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    visited[a] = true;
    q.push({ a, 0 });

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == b)
            return cnt;

        string str = to_string(cur);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 0 && j == 0)
                    continue;

                string temp = str;
                temp[i] = j + '0';
                int next = stoi(temp);

                if (prime[next] || visited[next])
                    continue;

                visited[next] = true;
                q.push({ next, cnt + 1 });
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    GetPrime();

    int T;
    cin >> T;

    int a, b;
    while (T--) {
        cin >> a >> b;

        int ans = BFS(a, b);
        if (ans != -1)
            cout << ans << "\n";
        else
            cout << "Impossible\n";
    }

    return 0;
}