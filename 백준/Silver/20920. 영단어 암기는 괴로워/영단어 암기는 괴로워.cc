#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length())
            return a.first < b.first;
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    unordered_map<string, int> um;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;

        if (s.length() < M)
            continue;

        um[s]++;
    }

    vector<pair<string, int>> words;
    for (auto m : um)
        words.push_back({m.first, m.second});
    sort(words.begin(), words.end(), cmp);

    for (auto word : words)
        cout << word.first << "\n";
    
    return 0;
}