#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shark {
    int r, c, s, d, z;
};

int R, C, M, answer;
vector<Shark> shark;
vector<int> board[101][101];

int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, 1, -1};

void Fishing(int idx) {
    for (int i = 1; i <= R; i++) {
        if (board[i][idx].empty())
            continue;

        answer += shark[board[i][idx][0]].z;
        shark[board[i][idx][0]].z = 0;
        board[i][idx].clear();
        return;
    }
}

void SharkMove(int idx) {
    int r = shark[idx].r;
    int c = shark[idx].c;
    int s = shark[idx].s;
    int d = shark[idx].d;
    int nr = r, nc = c;
    
    while (s > 0) {
        int cdr = dr[d];
        int cdc = dc[d];
        
        if (cdr > 0) {
            nr += s;
            s = 0;
            
            if (nr > R) {
                s = nr - R;
                nr = R;
                
                if (d == 1) d = 2;
                else if (d == 2) d = 1;
                else if (d == 3) d = 4;
                else if (d == 4) d = 3;
            }
        }
        else if (cdr < 0) {
            nr -= s;
            s = 0;

            if (nr < 1) {
                s = 1 - nr;
                nr = 1;

                if (d == 1) d = 2;
                else if (d == 2) d = 1;
                else if (d == 3) d = 4;
                else if (d == 4) d = 3;
            }
        }
        if (cdc > 0) {
            nc += s;
            s = 0;
            
            if (nc > C) {
                s = nc - C;
                nc = C;
                
                if (d == 1) d = 2;
                else if (d == 2) d = 1;
                else if (d == 3) d = 4;
                else if (d == 4) d = 3;
            }
        }
        else if (cdc < 0) {
            nc -= s;
            s = 0;

            if (nc < 1) {
                s = 1 - nc;
                nc = 1;

                if (d == 1) d = 2;
                else if (d == 2) d = 1;
                else if (d == 3) d = 4;
                else if (d == 4) d = 3;
            }
        }
    }
    
    shark[idx].r = nr;
    shark[idx].c = nc;
    shark[idx].d = d;
    board[nr][nc].push_back(idx);
}

void MoveShark() {
    for (int i = 0; i < shark.size(); i++) {
        if (shark[i].z != 0)
            board[shark[i].r][shark[i].c].clear();
    }
    
    for (int i = 0; i < shark.size(); i++) {
        if (shark[i].z != 0)
            SharkMove(i);
    }
}

bool cmp(int a, int b) {
    return shark[a].z > shark[b].z;
}

void KillShark() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (board[i][j].size() <= 1)
                continue;

            sort(board[i][j].begin(), board[i][j].end(), cmp);
            int liveShark = board[i][j][0];

            for (int k = 1; k < board[i][j].size(); k++) {
                shark[board[i][j][k]].z = 0;
            }

            board[i][j].clear();
            board[i][j].push_back(liveShark);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> M;
    
    int r, c, s, d, z;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        shark.push_back({r, c, s, d, z});
        board[r][c].push_back(i);
    } 

    for (int i = 1; i <= C; i++) {
        Fishing(i);
        MoveShark();
        KillShark();
    }

    cout << answer;
    
    return 0;
}