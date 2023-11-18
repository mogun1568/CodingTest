#include <iostream>

using namespace std;

long long a, b, c, t;

long long recursion(long long b) {
    if (b == 0) return 1;
	if (b == 1) return a % c;
	
	t = recursion(b / 2) % c;
	if (b % 2 == 0) return t * t % c;
	return t * t % c * a % c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b >> c;

    cout << recursion(b);
    
    return 0;
}