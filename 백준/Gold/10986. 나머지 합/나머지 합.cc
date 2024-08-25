#include <iostream>

using namespace std;

int N, M;
long long answer;
long long mod[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    int a, temp = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a;
        temp = (temp + a) % M;
        mod[temp]++;
    }

    for (int i = 0; i < M; i++) {
        answer += mod[i] * (mod[i] - 1) / 2;
    }
    answer += mod[0];

    cout << answer;
    
    return 0;
}