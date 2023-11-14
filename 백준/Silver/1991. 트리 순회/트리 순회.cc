#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[91]; // 아스키 코드 90 -> Z

void pre(char ap) {
    cout << ap;

    if (tree[ap][0] != '.') {
        pre(tree[ap][0]);
    }
    
    if (tree[ap][1] != '.') {
        pre(tree[ap][1]);
    }
}

void in(char ap) {
    if (tree[ap][0] != '.') {
        in(tree[ap][0]);
    }

    cout << ap;
    
    if (tree[ap][1] != '.') {
        in(tree[ap][1]);
    }
}

void post(char ap) {
    if (tree[ap][0] != '.') {
        post(tree[ap][0]);
    }

    if (tree[ap][1] != '.') {
        post(tree[ap][1]);
    }

    cout << ap;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    char p, l, r;
    for (int i = 0; i < n; i++) {
        cin >> p >> l >> r;

        if (l != '.') {
            tree[p].push_back(l);
        } else {
            tree[p].push_back('.');
        }
        if (r != '.') {
            tree[p].push_back(r);
        } else {
            tree[p].push_back('.');
        }
    }
    
    pre('A');
    cout << "\n";
    in('A');
    cout << "\n";
    post('A');
    
    return 0;
}