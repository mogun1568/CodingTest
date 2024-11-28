#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int visited[26];

void Dfs(string s, int idx) {
    if (idx == s.length()) {
        cout << s << "\n";
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (visited[i] < 1)
            continue;

        visited[i]--;
        s[idx] = i + 'a';
        Dfs(s, idx + 1);
        visited[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;
        memset(visited, false, sizeof(visited));
        for (auto i : s)
            visited[i - 'a']++;
        Dfs(s, 0);
    }
    
    return 0;
}