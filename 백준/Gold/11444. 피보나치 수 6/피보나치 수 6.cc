#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007

long long N;
typedef vector<vector<long long>> matrix;

matrix operator*(matrix &a, matrix &b) {
    matrix temp(2, vector<long long>(2));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= MOD;
        }
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    matrix ans = {{1, 0},
                  {0, 1}};
    matrix a = {{1, 1},
                {1, 0}};

    while (N > 0) {
        if (N % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        N /= 2;
    }

    cout << ans[0][1] << '\n';
    
    return 0;
}