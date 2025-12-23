#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[501];
bool visited[501];
bool flag;

void init(int n) {
    for (int i = 1; i <= n; i++) {
        tree[i].clear();
        visited[i] = false;
    }
}

void DFS(int cur, int pre) {
    visited[cur] = true;

    for (int next : tree[cur]) {
        if (next == pre)
            continue;

        if (visited[next]) {
            flag = true;
            continue;
        }

        DFS(next, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    for (int c = 1; ; c++) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        init(n);
        
        int a, b;
        while (m--) {
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        int T = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i])
                continue;

            flag = false;
            DFS(i, 0);

            if (!flag)
                T++;
        }

        cout << "Case " << c << ": ";
        if (T == 0)
            cout << "No trees.\n";
        else if (T == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << T << " trees.\n";
    }
    
    return 0;
}