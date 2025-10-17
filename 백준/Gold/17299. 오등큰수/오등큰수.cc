#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
int cnt[1000001];
int ans[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, a;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> a;
        arr[i] = a;
        cnt[a]++;
    }

    stack<int> st;
    st.push(arr[N]);
    for (int i = N - 1; i > 0; i--) {
        while (!st.empty() && cnt[st.top()] <= cnt[arr[i]])
            st.pop();

        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        st.push(arr[i]);
    }

    ans[N] = -1;
    for (int i = 1; i <= N; i++)
        cout << ans[i] << " ";
    
    return 0;
}