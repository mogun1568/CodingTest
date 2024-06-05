#include <iostream>

using namespace std;

int N;
int num[11][10];

void Dfs(int idx, int sum) {
    if (idx <= 0) {
        return;
    }
    
    for (int i = 0; i < 10; i++) {
        if (sum - num[idx][i] <= 0) {
            cout << i;
            Dfs(idx - 1, sum);
            break;
        }
        
        sum -= num[idx][i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < 10; i++) {
        num[1][i] = 1;
    }

    for (int i = 2; i <= 10; i++) {
        for (int j = 1; j < 10; j++) {
            num[i][j] = num[i - 1][j - 1] + num[i][j - 1];
        }
    }

    int sum = 0;
    bool check = false;
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (sum + num[i][j] >= N) {
                cout << j;
                
                Dfs(i - 1, N - sum);
                check = true;
                break;
            }
            
            sum += num[i][j];
        }

        if (check) {
            break;
        }
    }

    if (!check) {
        cout << -1;
    }
    
    return 0;
}