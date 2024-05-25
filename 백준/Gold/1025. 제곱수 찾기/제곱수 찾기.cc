#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N, M, answer = -1;
int arr[9][9];

bool isSquare(int num) {
    int temp = (int)sqrt(num);
    return temp * temp == num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (isSquare(arr[i][j])) {
                answer = max(answer, arr[i][j]);
            }
            
            for (int k = -N + 1; k < N; k++) {
                for (int l = -M + 1; l < M; l++) {
                    if (k == 0 && l == 0) {
                        continue;
                    }
                    
                    int r = i + k;
                    int c = j + l;
                    int num = arr[i][j];

                    while (r >= 0 && r < N && c >= 0 && c < M) {
                        num = num * 10 + arr[r][c];
                            
                        if (isSquare(num)) {
                            answer = max(answer, num);
                        }

                        r += k;
                        c += l;
                    }
                }
            }
        }
    }

    cout << answer;
    
    return 0;
}