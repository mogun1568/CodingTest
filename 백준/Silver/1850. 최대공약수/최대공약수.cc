#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	long long r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long a, b;
    cin >> a >> b;

    int cnt = gcd(a, b);

    for (int i = 0; i < cnt; i++) {
        cout << 1;
    }
    
    return 0;
}