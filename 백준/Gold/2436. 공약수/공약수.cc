#include <iostream>
#include <cmath>

using namespace std;

int A, B;

int Gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> A >> B;

    int divide = B / A, aa, ab;

    for (int i = 1; i <= sqrt(divide); i++) {
        if (divide % i != 0) {
            continue;
        }

        int a = i, b = divide / i;
        if (Gcd(a, b) == 1) {
            aa = a;
            ab = b;
        }
    }
    
    cout << aa * A << " " << ab * A;  
    
    return 0;
}