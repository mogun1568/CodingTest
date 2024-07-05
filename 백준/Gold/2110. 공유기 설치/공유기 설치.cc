#include <iostream>
#include <algorithm>

using namespace std;

int N, C, answer;
int house[200000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> house[i];
    }
    
    sort(house, house + N);

    int start = 1;
    int end = house[N - 1] - house[0];

    while (start <= end) {
        int mid = (start + end) / 2;
        
        int cnt = 1, preHouse = house[0];
        for (int i = 1; i < N; i++) {
            if (house[i] - preHouse >= mid) {
                cnt++;
                preHouse = house[i];
            }
        }

        if (cnt >= C) {
            answer = max(answer, mid);
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    cout << answer;
    
    return 0;
}