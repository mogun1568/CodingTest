#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000000

int N, S, answer = MAX;
int arr[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> S;

    int start = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        sum += arr[i];
        
        while (sum >= S) {
            answer = min(answer, i - start + 1);
            sum -= arr[start++];
        }
    }

    if (answer == MAX)
        cout << 0;
    else
        cout << answer;
    
    return 0;
}