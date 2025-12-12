#include <iostream>
#include <algorithm>
using namespace std;

struct Fish {
    int r, c;
    int dir;
    bool isDie;
};

int space[4][4];
Fish fish[17];
int ans;

int dr[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dc[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

void copyInfo(int copySpace[4][4], int originSpace[4][4], Fish copyFish[17], Fish originFish[17]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            copySpace[i][j] = originSpace[i][j];
    }

    for (int i = 1; i <= 16; i++) {
        copyFish[i] = originFish[i];
    }
}

void swapFish(int cIdx, int nIdx) {
    Fish temp = fish[cIdx];
    fish[cIdx].r = fish[nIdx].r;
    fish[cIdx].c = fish[nIdx].c;
    fish[nIdx].r = temp.r;
    fish[nIdx].c = temp.c;
}

void moveFish() {
    for (int i = 1; i <= 16; i++) {
        if (fish[i].isDie)
            continue;

        int r = fish[i].r;
        int c = fish[i].c;
        int dir = fish[i].dir;
        for (int j = 0; j < 8; j++) {
            int nDir = (dir + j - 1) % 8 + 1;
            int nr = r + dr[nDir];
            int nc = c + dc[nDir];

            if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4)
                continue;

            if (space[nr][nc] == -1)
                continue;

            fish[i].dir = nDir;
            if (space[nr][nc] == 0) {
                fish[space[r][c]].r = nr;
                fish[space[r][c]].c = nc;
            }
            else {
                swapFish(space[r][c], space[nr][nc]);
            }
            swap(space[r][c], space[nr][nc]);
            
            break;
        }
    }
}

void moveShark(int r, int c, int dir, int sum) {
    ans = max(ans, sum);

    int curSpace[4][4];
    Fish curFish[17];
    copyInfo(curSpace, space, curFish, fish);

    moveFish();

    space[r][c] = 0;
    for (int i = 1; i < 4; i++) {
        int nr = r + dr[dir] * i;
        int nc = c + dc[dir] * i;

        if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4)
            break;

        if (space[nr][nc] == 0)
            continue;

        int idx = space[nr][nc];
        space[nr][nc] = -1;
        fish[idx].isDie = true;
        
        moveShark(nr, nc, fish[idx].dir, sum + idx);

        space[nr][nc] = idx;
        fish[idx].isDie = false;
    }

    copyInfo(space, curSpace, fish, curFish);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a >> b;
            space[i][j] = a;
            fish[a].r = i;
            fish[a].c = j;
            fish[a].dir = b;
        }
    }

    int idx = space[0][0];
    space[0][0] = -1;
    fish[idx].isDie = true;
    moveShark(0, 0, fish[idx].dir, idx);

    cout << ans;
    
    return 0;
}