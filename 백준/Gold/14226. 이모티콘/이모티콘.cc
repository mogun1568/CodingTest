#include <iostream>
#include <queue>
using namespace std;

int S;
bool visited[1002][1002];

int BFS() {
    queue<pair<pair<int, int>, int>> q;
    visited[1][0] = true;
    q.push({{1, 0}, 0});

    while (!q.empty()) {
        int cs = q.front().first.first;
        int clipboard = q.front().first.second;
        int t = q.front().second;
        q.pop();
        
        if (cs == S)
            return t;

        // 클립보드에 복사하기
        int ns = cs;
        if (!visited[ns][cs]) {
            visited[ns][cs] = true;
            q.push({{ns, cs}, t + 1});
        }

        // 클립보드를 붙여넣기
        if (clipboard > 0) {
            ns = cs + clipboard;
            if (ns < S + 2 && !visited[ns][clipboard]) {
                visited[ns][clipboard] = true;
                q.push({{ns, clipboard}, t + 1});
            }
        }

        // 하나 삭제
        ns = cs - 1;
        if (ns > 0 && !visited[ns][clipboard]) {
            visited[ns][clipboard] = true;
            q.push({{ns, clipboard}, t + 1});
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