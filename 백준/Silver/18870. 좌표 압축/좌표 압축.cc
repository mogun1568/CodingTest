#include <iostream>
#include <algorithm>

using namespace std;

struct Coor {
    int x;
    int idx;
    int cnt;
};

Coor coor[1000000];

bool cmp1(const Coor &a, const Coor &b) {
    return a.x < b.x;
}

bool cmp2(const Coor &a, const Coor &b) {
    return a.idx < b.idx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> coor[i].x;
        coor[i].idx = i;
    }

    sort(coor, coor + n, cmp1);

    int a = -1, preX = 1000001;
    for (int i = 0; i < n; i++) {
        if (coor[i].x != preX) {
            a++;
            preX = coor[i].x;
        }

        coor[i].cnt = a;
    }

    sort(coor, coor + n, cmp2);

    for (int i = 0; i < n; i++) {
        cout << coor[i].cnt << ' ';
    }
    
    return 0;
}