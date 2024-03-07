#include <iostream>

using namespace std;

int tree[1000001][3];
bool cheak;

void dfs(int n, int pn) {
    if (n < pn) {
        return;
    } else {
        dfs(n, tree[pn][0]);
    }

    if (cheak) {
        return;
    }

    if (tree[pn][2] == 0) {
        tree[pn][2] = n;
        tree[n][0] = pn;
        cheak = true;
    }
}

void dfs2(int n) {
    if (tree[n][1] != 0) {
        dfs2(tree[n][1]);
    }
    
    if (tree[n][2] != 0) {
        dfs2(tree[n][2]);
    }

    cout << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, pn, r;

    cin >> n;
    r = n;
    tree[n][0] = 1000001;
    pn = n;

    while (cin >> n) {
        if (n < pn) {
            tree[pn][1] = n;
            tree[n][0] = pn;
        } else {
            cheak = false;
            dfs(n, pn);
        }  

        pn = n;
    }

    dfs2(r);
    
    return 0;
}