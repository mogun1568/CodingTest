#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<pair<int, int>> lecture;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    int s, e;
    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        lecture.push_back({s, e});
    }
    sort(lecture.begin(), lecture.end());

    priority_queue<int, vector<int>, greater<int>> lt;
    lt.push(lecture[0].second);
    
    for (int i = 1; i < N; i++) {
        int st = lecture[i].first;
        int et = lecture[i].second;

        if (st >= lt.top()) {
            lt.pop();
        }

        lt.push(et);
    }

    cout << lt.size();
    
    return 0;
}