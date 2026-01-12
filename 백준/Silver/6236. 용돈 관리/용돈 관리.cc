#include <iostream>
#include <algorithm>
using namespace std;

int money[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int maxMoney = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> money[i];
        maxMoney = max(maxMoney, money[i]);
        sum += money[i];
    }

    int start = maxMoney, end = sum, mid;
    while (start <= end) {
        mid = (start + end) / 2;
        int cur = mid, cnt = 1;

        for (int i = 0; i < N; i++) {
            if (money[i] > cur) {
                cur = mid;
                cnt++;
            }
            cur -= money[i];
        }

        if (cnt > M)
            start = mid + 1;
        else
            end = mid - 1;
    }

    cout << start;
    
    return 0;
}