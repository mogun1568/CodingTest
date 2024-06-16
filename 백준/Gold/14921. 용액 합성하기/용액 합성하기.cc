#include <iostream>
#include <cmath>

using namespace std;

int N, answer = 200000000;
int solution[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> solution[i];
    }

    int start = 0, end = N - 1, mid = 0;
    while (start < end) {
        mid = solution[start] + solution[end];

        if (mid == 0) {
            cout << 0;
            return 0;
        }

        if (abs(mid) <= abs(answer))
            answer = mid;
        
        if (mid < 0) 
            start++;
        else 
            end--;
    }

    cout << answer;
    
    return 0;
}