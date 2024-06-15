#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int A, B, N, M;
int arr[3];
int visited[MAX];

int Bfs() {
    queue<int> q;
    visited[N] = 1;
    q.push(N);

    while (!q.empty()) {
        int curStone = q.front();
        q.pop();

        if (curStone == M)
            break;

        for (int i = 0; i < 3; i++) {
            if (curStone + arr[i] >= 0 && curStone + arr[i] < MAX && visited[curStone + arr[i]] == 0) {
                visited[curStone + arr[i]] = visited[curStone] + 1;
                q.push(curStone + arr[i]);
            }
            if (curStone - arr[i] >= 0 && curStone - arr[i] < MAX && visited[curStone - arr[i]] == 0) {
                visited[curStone - arr[i]] = visited[curStone] + 1;
                q.push(curStone - arr[i]);
            }
        }
        for (int i = 1; i < 3; i++) {
            if (curStone * arr[i] < MAX && visited[curStone * arr[i]] == 0) {
                visited[curStone * arr[i]] = visited[curStone] + 1;
                q.push(curStone * arr[i]);
            }
        }
    }

    return visited[M] - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    arr[0] = 1;
    cin >> arr[1] >> arr[2] >> N >> M;

    cout << Bfs();
    
    return 0;
}