#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, answer = 1;
int weight[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> weight[i];
    sort(weight, weight + N);

    for (int i = 0; i < N; i++) {
        if (weight[i] > answer)
            break;
        
        answer += weight[i];
    }

    cout << answer;

    return 0;
}