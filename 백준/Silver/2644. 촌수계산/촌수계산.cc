#include <iostream>
#include <vector>

using namespace std;

vector<int> family[101];
bool check[101];
int de2, result = -1;

void dfs(int curN, int cnt) {
    if (curN == de2) {
        result = cnt;
        return;
    }

    for (int i = 0; i < family[curN].size(); i++) {
        if (!check[family[curN][i]]) {
            if (result != -1) {
                return;
            }

            check[family[curN][i]] = true;
            dfs(family[curN][i], cnt + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, de1, m, x, y;
    cin >> n >> de1 >> de2 >> m;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;

        family[x].push_back(y);
        family[y].push_back(x);
    }

    check[de1] = true;
    dfs(de1, 0);

    cout << result;
}