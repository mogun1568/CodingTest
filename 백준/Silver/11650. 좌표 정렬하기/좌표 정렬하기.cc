#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> coor;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coor.push_back({x, y});
    }

    // cmp안써도 알아서 first먼저 오름차순하고 같으면 second 오름차순 함
    sort(coor.begin(), coor.end());

    for (auto c : coor) {
        cout << c.first << " " << c.second << '\n';
    }
}