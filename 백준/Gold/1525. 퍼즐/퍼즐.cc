#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

const string goal = "123456780";
unordered_set<string> visited;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int BFS(string table) {
    queue<pair<string, int>> q;
    visited.insert(table);
    q.push({table, 0});

    while (!q.empty()) {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == goal)
            return cnt;

        int zeroIdx = cur.find('0');
        int r = zeroIdx / 3;
        int c = zeroIdx % 3;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= 3 || nc < 0 || nc >= 3)
                continue;

            string next = cur;
            swap(next[r * 3 + c], next[nr * 3 + nc]);

            if (visited.find(next) != visited.end())
                continue;

            visited.insert(next);
            q.push({next, cnt + 1});
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string table = "";
    char c;
    for (int i = 0; i < 9; i++) {
        cin >> c;
        table += c;
    }

    cout << BFS(table);
    
    return 0;
}