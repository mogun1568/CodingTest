#include <iostream>

using namespace std;

int R, C, T, answer;
int cHouse[51][51];
int nHouse[51][51];
int ap[2];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void Copy() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cHouse[i][j] = nHouse[i][j];
            nHouse[i][j] = 0;
        }
    }
}

void Spread(int r, int c) {
    int amount = cHouse[r][c] / 5;
    
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 1 || nr > R || nc < 1 || nc > C)
            continue;

        if (nHouse[nr][nc] == -1)
            continue;

        nHouse[nr][nc] += amount;
        nHouse[r][c] -= amount;
    }
    nHouse[r][c] += cHouse[r][c];
}

void Dust() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (cHouse[i][j] == 0)
                continue;
            else if (cHouse[i][j] < 5)
                nHouse[i][j] = cHouse[i][j];
        }
    }
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (cHouse[i][j] >= 5)
                Spread(i, j);
        }
    }

    Copy();
}

void AirPurifierUp() {
    cHouse[ap[0] - 1][1] = 0;
    
    for (int i = ap[0] - 2; i > 0; i--) {
        if (cHouse[i][1] > 0) {
            cHouse[i + 1][1] = cHouse[i][1];
            cHouse[i][1] = 0;
        }
    }
    for (int i = 2; i <= C; i++) {
        if (cHouse[1][i] > 0) {
            cHouse[1][i - 1] = cHouse[1][i];
            cHouse[1][i] = 0;
        }
    }
    for (int i = 2; i <= ap[0]; i++) {
        if (cHouse[i][C] > 0) {
            cHouse[i - 1][C] = cHouse[i][C];
            cHouse[i][C] = 0;
        }
    }
    for (int i = C - 1; i > 1; i--) {
        if (cHouse[ap[0]][i] > 0) {
            cHouse[ap[0]][i + 1] = cHouse[ap[0]][i];
            cHouse[ap[0]][i] = 0;
        }
    }
}

void AirPurifierDown() {
    cHouse[ap[1] + 1][1] = 0;

    for (int i = ap[0] + 2; i <= R; i++) {
        if (cHouse[i][1] > 0) {
            cHouse[i - 1][1] = cHouse[i][1];
            cHouse[i][1] = 0;
        }
    }
    for (int i = 2; i <= C; i++) {
        if (cHouse[R][i] > 0) {
            cHouse[R][i - 1] = cHouse[R][i];
            cHouse[R][i] = 0;
        }
    }
    for (int i = R - 1; i >= ap[1]; i--) {
        if (cHouse[i][C] > 0) {
            cHouse[i + 1][C] = cHouse[i][C];
            cHouse[i][C] = 0;
        }
    }
    for (int i = C - 1; i > 1; i--) {
        if (cHouse[ap[1]][i] > 0) {
            cHouse[ap[1]][i + 1] = cHouse[ap[1]][i];
            cHouse[ap[1]][i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> T;

    int k = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> cHouse[i][j];

            if (cHouse[i][j] == -1) {
                ap[k] = i;
                k++;
            }
        }
    }

    while(T--) {
        Dust();
        AirPurifierUp();
        AirPurifierDown();
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (cHouse[i][j] <= 0)
                continue;

            answer += cHouse[i][j];
        }
    }

    cout << answer;
    
    return 0;
}