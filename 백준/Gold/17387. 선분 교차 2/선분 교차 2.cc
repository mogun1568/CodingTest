#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> point;

int CCW(point a, point b, point c) {
    ll temp = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);

    if (temp > 0) return 1;
    else if (temp < 0) return -1;
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    point a, b, c, d;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;
    cin >> d.first >> d.second;

    int abc = CCW(a, b, c);
    int abd = CCW(a, b, d);
    int cda = CCW(c, d, a);
    int cdb = CCW(c, d, b);

    // 일직선인 경우
    if (abc * abd == 0 && cda * cdb == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);

        if (a <= d && c <= b)
            cout << 1;
        else
            cout << 0;
    }
    // 교차거나 점만 걸치는 경우
    else if (abc * abd <= 0 && cda * cdb <= 0)
        cout << 1;
    // 교차 안하는 경우
    else
        cout << 0;
    
    return 0;
}