#include <iostream>
using namespace std;

int N;
int arr[81];
bool isDone;

void DFS(int idx) {
    for (int i = 1; i <= idx / 2; i++) {
        bool isSame = true;
        for (int j = 0; j < i; j++) {
            if (arr[idx - j] != arr[idx - i - j]) {
                isSame = false;
                break;
            }
        }

        if (isSame)
            return;
    }

    if (idx == N) {
        isDone = true;
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (isDone)
            return;
        
        arr[idx + 1] = i;
        DFS(idx + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    arr[1] = 1;
    DFS(1);

    for (int i = 1; i <= N; i++)
        cout << arr[i];
    
    return 0;
}