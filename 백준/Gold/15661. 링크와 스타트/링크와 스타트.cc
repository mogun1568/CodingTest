#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int graph[20][20];
bool visited[20];
int answer = 987654321;

int cal() {
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (visited[i] && visited[j]) {
				cnt1 += graph[i][j] + graph[j][i];
			} else if (!visited[i] && !visited[j]) {
				cnt2 += graph[i][j] + graph[j][i];
			}
		}
	}
    
	return abs(cnt1 - cnt2);
}
void combination(int cnt, int idx) {
	if (cnt > n / 2 || answer == 0) {
		return;
	}
    
	if (cnt > 0) {
		answer = min(cal(), answer);
        if (answer == 0) {
            return;
        }
	}
    
	for (int i = idx; i < n; i++) {
		visited[i] = true;
		combination(cnt + 1, i + 1);
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	combination(0, 0);
    
	cout << answer;
    
	return 0;
}