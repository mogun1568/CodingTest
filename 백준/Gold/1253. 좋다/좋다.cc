#include <iostream>
#include <algorithm>

using namespace std;

int N, answer;
int arr[2000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    if (N < 3) {
        cout << 0;
        return 0;
    }
    
    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        int start = 0, end = N - 1;

        while (start < end) {
            if (arr[start] + arr[end] < arr[i])
                start++;
            else if (arr[start] + arr[end] > arr[i])
                end--;
            else {
                if (start == i)
                    start++;
                else if (end == i)
                    end--;
                else {
                    answer++;
                    break;
                }
            }
        }
    }

    cout << answer;
    
    return 0;
}