#include <iostream>
#include <algorithm>
using namespace std;

int buildings[50];
int cnt[50];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> buildings[i];

    for (int i = 0; i < N; i++) {
        double maxSlope = -1e9;
        for (int j = i + 1; j < N; j++) {
            double slope = (double)(buildings[j] - buildings[i]) / (j - i);
            if (slope <= maxSlope)
                continue;

            maxSlope = slope;
            cnt[i]++;
            cnt[j]++;
        }
    }

    cout << *max_element(cnt, cnt + N);
    
    return 0;
}