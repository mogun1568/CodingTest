#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> room[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> room[i].second >> room[i].first;
    sort(room, room + N);

    int cnt = 1, end = room[0].first;
    for (int i = 1; i < N; i++) {
        if (room[i].second < end)
            continue;

        cnt++;
        end = room[i].first;
    }

    cout << cnt;
    
    return 0;
}