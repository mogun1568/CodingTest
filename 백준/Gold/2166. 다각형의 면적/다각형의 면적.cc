#include <iostream>
#include <cmath>

using namespace std;

double coor[10000][2];

double solve(double x1, double y1, double x2, double y2, double x3, double y3) {
	double res = x1 * y2 + x2 * y3 + x3 * y1;
	res -= (x2 * y1 + x3 * y2 + x1 * y3);
	return res / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    double result = 0;
    cin >> coor[0][0] >> coor[0][1];
    cin >> coor[1][0] >> coor[1][1];
    for (int i = 2; i < n; i++) {
        cin >> coor[i][0] >> coor[i][1];

        result += solve(coor[0][0], coor[0][1], coor[i - 1][0], coor[i - 1][1], coor[i][0], coor[i][1]);
    }

    cout << fixed;
	cout.precision(1);
	cout << abs(result) << endl;

    return 0;
}