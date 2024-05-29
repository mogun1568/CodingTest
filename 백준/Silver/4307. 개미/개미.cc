#include <iostream>
#include <algorithm>

using namespace std;

int T, L, N;
int ant[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    while (T--) {
        cin >> L >> N;
        for (int i = 0; i < N; i++) {
            cin >> ant[i];
        }
        sort(ant, ant + N);

        int idx, a = min(L - ant[0], ant[N - 1]), b;
        for (int i = 1; i < N; i++) {
            a = min(a, max(ant[i - 1], L - ant[i]));
        }
    
        b = max(L - ant[0], ant[N - 1]);
    
        cout << a << " " << b << "\n";
    }
    
    return 0;
}