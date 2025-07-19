#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int visited[1000001];

void BFS() {
    queue<int> q;
    visited[S] = 1;
    q.push(S);

    while (!q.empty()) {
        int curF = q.front();
        q.pop();

        if (curF == G) {
            cout << visited[curF] - 1;
            return;
        }

        int nextF = curF + U;
        if (nextF <= F && visited[nextF] == 0) {
            visited[nextF] = visited[curF] + 1;
            q.push(nextF);
        }

        nextF = curF - D;
        if (nextF > 0 && visited[nextF] == 0) {
            visited[nextF] = visited[curF] + 1;
            q.push(nextF);
        }
    }

    cout << "use the stairs";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> F >> S >> G >> U >> D;

    BFS();
    
    return 0;
}