#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Info {
    int r, c;
    int dir;
};

int N, K;
int board[13][13];
vector<int> pieceStack[13][13];
Info pieces[11];

int dr[] = {0, 0, 0, -1, 1};
int dc[] = {0, 1, -1, 0, 0};
int opp[] = {0, 2, 1, 4, 3};

int solve() {
    for (int turn = 1; turn <= 1000; turn++) {
        for (int num = 1; num <= K; num++) {
            int r = pieces[num].r;
            int c = pieces[num].c;
            int dir = pieces[num].dir;
            
            int nr = r + dr[dir];
            int nc = c + dc[dir];
    
            // 체스판을 벗어나거나 파란색인 경우
            if (nr < 1 || nr > N || nc < 1 || nc > N || board[nr][nc] == 2) {
                pieces[num].dir = opp[dir];
                dir = pieces[num].dir;
                nr = r + dr[dir];
                nc = c + dc[dir];
    
                // 방향을 바꿨는데도 체스판을 벗어나거나 파란색인 경우
                if (nr < 1 || nr > N || nc < 1 || nc > N || board[nr][nc] == 2) {
                    continue;
                }
            }
    
            auto& cur = pieceStack[r][c];
            auto& next = pieceStack[nr][nc];
            
            // 현재 칸에서 num번 말이 어디 있는지 찾기
            auto it = find(cur.begin(), cur.end(), num);
        
            // 말 뭉치 복사
            vector<int> movingPieces(it, cur.end());
        
            // 원래 칸에서 삭제
            cur.erase(it, cur.end());
        
            // 빨간색이면 뒤집기
            if (board[nr][nc] == 1)
                reverse(movingPieces.begin(), movingPieces.end());
        
            // 다음 칸에 붙이고 좌표 정보 갱신
            for (int id : movingPieces) {
                next.push_back(id);
                pieces[id].r = nr;
                pieces[id].c = nc;
            }
    
            // 말 갯수 확인
            if (next.size() >= 4)
                return turn;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    }

    int a, b, c;
    for (int i = 1; i <= K; i++) {
        cin >> a >> b >> c;
        pieceStack[a][b].push_back(i);
        pieces[i] = {a, b, c};
    }

    cout << solve();
    
    return 0;
}