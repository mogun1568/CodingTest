#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x, y, result = 0;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);

    vector<pair<int, int>> line;
    line.push_back(v[0]);

    for (int i = 1; i < n; i++) {
        if (v[i].first > line.back().second) {
            line.push_back(v[i]);
        } else {
            line.back().second = max(line.back().second, v[i].second);
        }
    }

    for (int i = 0; i < line.size(); i++) {
        result += line[i].second - line[i].first;
    }

    cout << result;
    
    return 0;
}