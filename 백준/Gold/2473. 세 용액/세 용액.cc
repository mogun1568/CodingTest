#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define INF 3000000000

int N;
long long solution[5000];
long long answer[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> solution[i];
    
    sort(solution, solution + N);
    long long minSum = INF;
    
    for (int i = 0; i < N; i++) {
        long long start = 0;
        long long end = N - 1;
        long long mid = 0;

        if (i == 0)
            start = 1;
        else if (i == N - 1)
            end = N - 2;

        while (start < end) {
            mid = solution[i] + solution[start] + solution[end];

            if (abs(mid) < minSum) {
                minSum = abs(mid);
                answer[0] = solution[i];
                answer[1] = solution[start];
                answer[2] = solution[end];
            }
            
            if (mid < 0) {
                start++;
                if (start == i)
                    start++;
            }
            else {
                end--;
                if (end == i)
                    end--;
            }
        }
    }

    sort(answer, answer + 3);

    for (int i = 0; i < 3; i++)
        cout << answer[i] << " ";
    
    return 0;
}