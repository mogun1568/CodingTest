#include <iostream>
#include <cstring>

using namespace std;

int T, n, cnt;
int student[100001];
bool visited[100001];
bool result[100001];

void Dfs(int cur) {
    visited[cur] = true;
    int next = student[cur];

    if (!visited[next])
        Dfs(next);
    else if (!result[next]) {
        for (int i = next; i != cur; i = student[i])
            cnt++;
        cnt++;
    }
        

    result[cur] = true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> student[i];
        }

        cnt = 0;
        memset(visited, false, sizeof(visited));
        memset(result, false, sizeof(result));
        
        for (int i = 1; i <= n; i++) {
            if (visited[i])
                continue;

            Dfs(i);
        }

        cout << n - cnt << "\n";
    }
    
    return 0;
}