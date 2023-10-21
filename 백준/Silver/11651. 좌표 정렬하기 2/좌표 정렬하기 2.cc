#include <iostream>
#include <algorithm>

using namespace std;

struct Coor
{
    int x;
    int y;
};

bool cmp(const Coor &a, const Coor &b) {
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    Coor coor[n];
    for (int i = 0; i < n; i++) {
        cin >> coor[i].x >> coor[i].y;
    }
    
    sort(coor, coor + n, cmp);
    
    for (auto c : coor) {
        cout << c.x << ' ' << c.y << '\n';
    }

    return 0;
}