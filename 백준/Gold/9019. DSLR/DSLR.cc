#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

bool visited[10000];

string BFS(int a, int b) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, string>> q;
    visited[a] = true;
    q.push({a, ""});

    while (!q.empty()) {
        int c = q.front().first;
        string cmd = q.front().second;
        q.pop();

        if (c == b)
            return cmd;

        int n = (c * 2) % 10000;
        if (!visited[n]) {
            visited[n] = true;
            q.push({n, cmd + "D"});
        }

        n = (c - 1 < 0) ? 9999 : c - 1;
        if (!visited[n]) {
            visited[n] = true;
            q.push({n, cmd + "S"});
        }

        n = (c % 1000) * 10 + c / 1000;
        if (!visited[n]) {
            visited[n] = true;
            q.push({n, cmd + "L"});
        }

        n = (c % 10) * 1000 + c / 10;
        if (!visited[n]) {
            visited[n] = true;
            q.push({n, cmd + "R"});
        }
    }

    return "";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;

        cout << BFS(A, B) << "\n";
    }
    
    return 0;
}