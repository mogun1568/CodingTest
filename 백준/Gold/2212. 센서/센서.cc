#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, s, sum = 0;
    cin >> n >> k;

    vector<int> sensor, interval;
    for (int i = 0; i < n; i++) {
        cin >> s;
        sensor.push_back(s);
    }
    sort(sensor.begin(), sensor.end());

    for (int i = 1; i < n; i++) {
        interval.push_back(sensor[i] - sensor[i - 1]);
    }
    sort(interval.begin(), interval.end());

    for (int i = 0; i < n - k; i++) {
        sum += interval[i];
    }

    cout << sum;
    
    return 0;
}