#include <iostream>
#include <stack>
using namespace std;

int top[500001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    stack<int> st;
    for (int i = 1; i <= N; i++) {
        cin >> top[i];

        while (1) {
            if (st.empty()) {
                cout << 0 << " ";
                break;
            }
            
            if (top[st.top()] < top[i])
                st.pop();
            else {
                cout << st.top() << " ";
                break;
            }
        }

        st.push(i);
    } 
    
    return 0;
}