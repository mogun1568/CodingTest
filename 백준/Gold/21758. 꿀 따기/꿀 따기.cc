#include <iostream>
#include <algorithm>

using namespace std;

int N, answer;
int bees[100001];
int sums[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> bees[i];
        sums[i] = bees[i] + sums[i - 1];
    }

    // 벌 - 통 - 벌   
    for (int i = 2; i < N; i++) {
        int curSum = (sums[i] - sums[1]) + (sums[N - 1] - sums[i - 1]);
        answer = max(answer, curSum);
    }

    // 벌 - 벌 - 통   
    for (int i = 2; i < N; i++) {
        int curSum = (sums[N] - sums[1] - bees[i]) + (sums[N] - sums[i]);
        answer = max(answer, curSum);
    }

    // 통 - 벌 - 벌   
    for (int i = 2; i < N; i++) {
        int curSum = (sums[N - 1]  - bees[i]) + sums[i - 1];
        answer = max(answer, curSum);
    }

    cout << answer;
    
    return 0;
}