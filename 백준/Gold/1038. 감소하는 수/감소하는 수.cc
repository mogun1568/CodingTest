#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<long long> v;
queue<long long> q;

void bfs() {
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
        q.push(i);
    }

    while (!q.empty()) {
        long long num = q.front();
        int last = num % 10;
        q.pop();
        
        for (int i = 0; i < last; i++) {
            v.push_back(num * 10 + i);
            q.push(num * 10 + i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    bfs();

    if (n >= v.size()) {
        cout << -1;
    } else {
        cout << v[n];
    }

    return 0;
}