#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, answer;
vector<pair<int, int>> lecture;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    int a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        lecture.push_back({b, c});
    }
    sort(lecture.begin(), lecture.end());

    priority_queue<int, vector<int>, greater<int>> lastTime;
    for (int i = 0; i < N; i++) {
        int startTime = lecture[i].first;
		int endTime = lecture[i].second;

		if (lastTime.empty()) {
			lastTime.push(endTime);
		} else {
			if (lastTime.top() > startTime) {
				answer++;
			} else {
				lastTime.pop();
			}
			lastTime.push(endTime);
		}
    }

    cout << answer + 1;
    
    return 0;
}