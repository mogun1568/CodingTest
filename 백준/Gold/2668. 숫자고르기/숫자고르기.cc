#include <iostream>

using namespace std;

int result;
int table[101];
bool visited[101];
bool check;

void dfs(int curN, int startN, int cnt) {
    if (curN == startN) {
        result += cnt;
        check = true;
        return;
    }

    if (visited[curN]) {
        return;
    }
    
    visited[curN] = true;
    dfs(table[curN], startN, cnt + 1);

    if (!check) {
        visited[curN] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> table[i];
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        dfs(table[i], i, 1);

        if (!check) {
            visited[i] = false;
        }
        check = false;
    }

    cout << result << "\n";
    for (int i = 1; i <= 100; i++) {
        if (visited[i]) {
            cout << i << "\n";
        }
    }
    
    return 0;
}