#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> fri[51];
bool visited[51];
int score[51];
int minFri = 100;
vector<int> cnt;

void Bfs(int a) {
    memset(visited, false, sizeof(visited));
    score[a] = 0;
    int s = 0;
    queue<int> q;
    visited[a] = true;
    q.push(a);

    while (!q.empty()) {
        int ca = q.front();
        q.pop();

        for (int i = 0; i < fri[ca].size(); i++) {
            int na = fri[ca][i];

            if (visited[na]) {
                continue;
            }

            score[na] = score[ca] + 1;
            visited[na] = true;
            s = score[na];
            q.push(na);
        }
    }

    if (s < minFri) {
        minFri = s;
        cnt.clear(); 
        cnt.push_back(a);
    } else if (s == minFri) {
        cnt.push_back(a);
    }
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a, b;
    cin >> n;

    while (true) {
        cin >> a >> b;
        if (a == -1) {
            break;
        }

        fri[a].push_back(b);
        fri[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        Bfs(i);
    }

    cout << minFri << " " << cnt.size() << "\n";
    for (auto c : cnt) {
        cout << c << " ";
    }
    
    return 0;
}