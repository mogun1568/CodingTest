#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int N, L, answer;
int map[100][100];
bool visited[100];

bool RowCheck(int r) {
    memset(visited, false, sizeof(visited));
    
    for (int i = 1; i < N; i++) {
        if (abs(map[r][i - 1] - map[r][i]) > 1)
            return false;

        if (map[r][i - 1] - map[r][i] == 1) {
            if (i - 1 + L > N)
                return false;
            
            for (int j = i; j < i + L; j++) {
                if (map[r][j] != map[r][i] || visited[j])
                    return false;

                visited[j] = true;
            }
            i += L - 1;
        }
        else if (map[r][i - 1] - map[r][i] == -1) {
            if (i - L < 0)
                return false;
            
            for (int j = i - 1; j >= i - L; j--) {
                if (map[r][j] != map[r][i - 1] || visited[j]) 
                    return false;

                visited[j] = true;
            }
        }
    }

    return true;
}

bool ColumnCheck(int c) {
    memset(visited, false, sizeof(visited));
    
    for (int i = 1; i < N; i++) {
        if (abs(map[i - 1][c] - map[i][c]) > 1)
            return false;

        if (map[i - 1][c] - map[i][c] == 1) {
            if (i - 1 + L > N)
                return false;
            
            for (int j = i; j < i + L; j++) {
                if (map[j][c] != map[i][c] || visited[j])
                    return false;

                visited[j] = true;
            }
            i += L - 1;
        }
        else if (map[i - 1][c] - map[i][c] == -1) {
            if (i - L < 0)
                return false;
            
            for (int j = i - 1; j >= i - L; j--) {
                if (map[j][c] != map[i - 1][c] || visited[j])
                    return false;

                visited[j] = true;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        if (RowCheck(i)) answer++;
        if (ColumnCheck(i)) answer++;
    }

    cout << answer;
    
    return 0;
}