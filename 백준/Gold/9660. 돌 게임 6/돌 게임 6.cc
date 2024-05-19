#include <iostream>

using namespace std;

long long N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    // 1 = SK
    // 2 = CY
    // 3 = SK
    // 4 = SK
    // 5 = SK
    // 6 = SK
    // 7 = CY

    if (N % 7 == 2 || N % 7 == 0) {
        cout << "CY";
    }
    else {
        cout << "SK";
    }
    
    return 0;
}