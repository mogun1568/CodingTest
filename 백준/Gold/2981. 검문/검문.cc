#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int N, gcd;
int arr[100];
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


    gcd = arr[1] - arr[0];
    for (int i = 2; i < N; i++)
        gcd = Gcd(max(gcd, arr[i] - arr[i - 1]), min(gcd, arr[i] - arr[i - 1]));

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