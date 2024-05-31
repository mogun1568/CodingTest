#include <iostream>
#include <algorithm>

using namespace std;

int X, N;
int rego[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> X >> N) {
        for (int i = 0; i < N; i++) {
            cin >> rego[i];
        }

        if (N < 2) {
            cout << "danger\n";
            continue;
        }

        X *= 10000000;
        sort(rego, rego + N);
    
        int start = 0, end = N - 1, mid;
        while (start < end) {
            mid = rego[start] + rego[end];
            
            if (mid < X) {
                start++;
            }
            else if (mid > X) {
                end--;
            }
            else {
                break;
            }
        }
    
        if (mid == X) {
            cout << "yes " << rego[start] << " " << rego[end] << "\n";
        }
        else {
            cout << "danger\n";
        }
    } 
    
    return 0;
}