#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001

int arr[MAX];

int BFS(int n, int k) {
    queue<int> q;
    arr[n] = 1;
    q.push(n);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == k)
            break;

        int nx = 2 * x;
        if (nx < MAX && arr[nx] == 0) {
            arr[nx] = arr[x];
            q.push(nx);
        }

        nx = x - 1;
        if (nx >= 0 && arr[nx] == 0) {
            arr[nx] = arr[x] + 1;
            q.push(nx);
        }

        nx = x + 1;
        if (nx < MAX && arr[nx] == 0) {
            arr[nx] = arr[x] + 1;
            q.push(nx);
        }
    }

    return arr[k] - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    cout << BFS(N, K);
        
    return 0;
}