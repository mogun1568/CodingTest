#include <iostream>
using namespace std;

void Hanoi(int n, int start, int mid, int end) {
    if (n == 1) {
        cout << start << " " << end << "\n";
        return;
    }

    Hanoi(n - 1, start, end, mid);
    cout << start << " " << end << "\n";
    Hanoi(n - 1, mid, start, end);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    cout << (1 << N) - 1 << "\n";
    Hanoi(N, 1, 2, 3);
    
    return 0;
}