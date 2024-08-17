#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define MAX 100001

int N, K;
int point[MAX];
bool visited[MAX];

void Bfs() {
    queue<int> q;
    q.push(N);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (cur == K) {
            return;
        }

        int next = cur - 1;
        if (next >= 0 && point[next] == -1) {
            point[next] = cur;
            q.push(next);
        }

        next = cur + 1;
        if (next < MAX && point[next] == -1) {
            point[next] = cur;
            q.push(next);
        }

        next = cur * 2;
        if (next < MAX && point[next] == -1) {
            point[next] = cur;
            q.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;

    for (int i = 0; i < MAX; i++) {
        point[i] = -1;
    }

    Bfs();

    stack<int> st;
    int n = K;
    st.push(n);
    while (n != N) {
        n = point[n];
        st.push(n);
    }

    cout << st.size() - 1 << "\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }   
    
    return 0;
}