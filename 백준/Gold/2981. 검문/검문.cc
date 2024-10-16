#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int N, gcd;
int arr[100];
int diff[99];
set<int> s;

int Gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);

    for (int i = 0; i < N - 1; i++)
        diff[i] = arr[i + 1] - arr[i];

    gcd = diff[0];
    for (int i = 1; i < N - 1; i++)
        gcd = Gcd(max(gcd, diff[i]), min(gcd, diff[i]));

    for (int i = 2; i <= gcd / 2; i++) {
        if (gcd % i == 0) {
            s.insert(i);
            s.insert(gcd / i);
        }
    }
    s.insert(gcd);

    for (auto i : s)
        cout << i << "\n";

    return 0;
}