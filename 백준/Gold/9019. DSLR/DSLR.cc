#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int T, A, B;
bool visited[10000];

void DSLR() {
    memset(visited, false, sizeof(visited));
    queue<pair<int, string>> q;
    visited[A] = true;
    q.push({A, ""});

    while (!q.empty()) {
        int a = q.front().first;
        string cmd = q.front().second;
        q.pop();

        if (a == B) {
            cout << cmd << "\n";
            return;
        }

        // D
        int n = (a * 2) % 10000;
        if (!visited[n]) {  
            visited[n] = true;
            q.push({n, cmd + "D"});
        }
    
        // S
        n = a - 1 < 0 ? 9999 : a - 1;
        if (!visited[n]) {
            visited[n] = true;
            q.push({n, cmd + "S"});
        }
        
        // L
        n = (a % 1000) * 10 + (a / 1000);
        if (!visited[n]) {
            visited[n] = true;
            q.push({n, cmd + "L"});
        }
        
        // R
        n = a / 10 + (a % 10) * 1000;
        if (!visited[n]) {
            visited[n] = true;
            q.push({n, cmd + "R"});
        }
    }   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        cin >> A >> B;
        DSLR();
    }
    
    return 0;
}