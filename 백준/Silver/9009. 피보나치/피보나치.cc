#include <iostream>
#include <stack>

using namespace std;

long long fibo[46];
stack<long long> s;

long long solue (long long n) {
    int i = 1;
    while (fibo[i] <= n) {
        i++;
    }

    s.push(fibo[i - 1]);
    return fibo[i - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 46; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    long long n;
    while (t--) {
        cin >> n;

        while (n > 0) {
            n -= solue(n);
        }

        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << "\n";
    }
    
    return 0;
}