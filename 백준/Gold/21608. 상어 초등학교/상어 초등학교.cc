#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
int clas[21][21];
vector<int> fr[401];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void solve(int ms) {
    int rf = 0, re = 0, rr = 0, rc = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (clas[i][j] != 0) {
                continue;
            }
            
            int f = 0, e = 0, r = i, c = j;           
            for (int k = 0; k < 4; k++) {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if (nr <= 0 || nr > n || nc <= 0 || nc > n) {
                    continue;
                }

                for (int l = 0; l < 4; l++) {
                    if (clas[nr][nc] == fr[ms][l]) {
                        f++;
                        break;
                    }
                }

                if (clas[nr][nc] == 0) {
                    e++;
                }
            }

            if (f > rf) {
                rf = f;
                re = e;
                rr = r;
                rc = c;
            } else if (f == rf) {
                if (e > re) {
                    re = e;
                    rr = r;
                    rc = c;
                }
            } else {
                continue;
            }

            if (rr == 0 && rc == 0) {
                rr = r, rc = c;
            }
        }
    }

    clas[rr][rc] = ms;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int ms, fri, result = 0;
    cin >> n;

    for (int i = 0; i < n * n; i++) {
        cin >> ms;

        for (int j = 0; j < 4; j++) {
            cin >> fri;
            fr[ms].push_back(fri);
        }

        solve(ms);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int ms = clas[i][j], f = 0;
            for (int k = 0; k < 4; k++) {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if (nr <= 0 || nr > n || nc <= 0 || nc > n) {
                    continue;
                }

                for (int l = 0; l < 4; l++) {
                    if (clas[nr][nc] == fr[ms][l]) {
                        f++;
                        break;
                    }
                }
            }

            if (f != 0) {
                result += pow(10, f - 1);
            }
        }
    }

    cout << result;
    
    return 0;
}