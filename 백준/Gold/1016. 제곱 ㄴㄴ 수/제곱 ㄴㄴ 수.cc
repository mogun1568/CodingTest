#include <iostream>

using namespace std;

long long Min, Max, answer;
bool num[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> Min >> Max;

    answer = Max - Min + 1;

    for (long long i = 2; i * i <= Max; i++) {
        long long temp = Min / (i * i);
        if (temp * (i * i) < Min)
            temp++;

        while (temp * (i * i) <= Max) {
            if (!num[temp * (i * i) - Min]) {
                num[temp * (i * i) - Min] = true;
                answer--;
            }
            temp++;
        }
    }

    cout << answer;
    
    return 0;
}