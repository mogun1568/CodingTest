#include <iostream>
#include <queue>
using namespace std;

int S;
int visited[1002][1002];

int BFS() {
    queue<pair<int, int>> q;
    visited[1][0] = 1;
    q.push({1, 0});

    while (!q.empty()) {
        int cs = q.front().first;
        int clipboard = q.front().second;
        q.pop();

        if (cs == S)
            return visited[cs][clipboard] - 1;

        // 클립보드에 복사하기
        int ns = cs;
        if (visited[ns][cs] == 0) {
            visited[ns][cs] = visited[cs][clipboard] + 1;
            q.push({ns, cs});
        }

        // 클립보드를 붙여넣기
        if (clipboard > 0) {
            ns = cs + clipboard;
            if (ns < S + 2 && visited[ns][clipboard] == 0) {
                visited[ns][clipboard] = visited[cs][clipboard] + 1;
                q.push({ns, clipboard});
            }
        }

        // 하나 삭제
        ns = cs - 1;
        if (ns > 0 && visited[ns][clipboard] == 0) {
            visited[ns][clipboard] = visited[cs][clipboard] + 1;
            q.push({ns, clipboard});
        }
        
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;

    cout << BFS();
    
    return 0;
}