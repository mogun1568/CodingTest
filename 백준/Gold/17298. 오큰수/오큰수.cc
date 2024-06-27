#include <iostream>
#include <stack>

using namespace std;

int N;
int A[1000000];
stack<pair<int, int>> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;

        while (!s.empty() && a > s.top().first) {
            A[s.top().second] = a;
            s.pop();
        }

        s.push({a, i});
    }

    while (!s.empty()) {
        A[s.top().second] = -1;
        s.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    
    return 0;
}