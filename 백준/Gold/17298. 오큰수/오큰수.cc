#include <iostream>
#include <stack>
using namespace std;

int arr[1000000];
stack<pair<int, int>> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, a;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;

        while (!st.empty() && a > st.top().first) {
            arr[st.top().second] = a;
            st.pop();
        }

        st.push({a, i});
    }

    while (!st.empty()) {
        arr[st.top().second] = -1;
        st.pop();
    }

    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    
    return 0;
}