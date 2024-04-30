#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

string S, T;

int Bfs() {
    queue<string> q;
    q.push(T);

    while (!q.empty()) {
        string str = q.front();
        q.pop();

        if (str == S) {
            return 1;
        }
        
        if (str.back() == 'A') {
            q.push(str.substr(0, str.size() - 1));
        }
        if (str.front() == 'B') {
            reverse(str.begin(), str.end());
            q.push(str.substr(0, str.size() - 1));
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S >> T;

    cout << Bfs();
    
    return 0;
}