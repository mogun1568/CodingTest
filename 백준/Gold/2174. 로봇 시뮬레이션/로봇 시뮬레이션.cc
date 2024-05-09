#include <iostream>

using namespace std;

int A, B, N, M;
int ground[101][101][2];
int robot[101][2];
bool check;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void Command(int r, char c, int n) {
    int x = robot[r][0];
    int y = robot[r][1];
    int d = ground[x][y][1];

    if (c == 'L') {
        d = (d - n + 100) % 4;
        ground[x][y][1] = d;
    } else if (c == 'R') {
        d = (d + n) % 4;
        ground[x][y][1] = d;
    } else {
        ground[x][y][0] = 0;
        ground[x][y][1] = 0;
        
        for (int i = 0; i < n; i++) {
            x += dr[d];
            y += dc[d];

            if (x < 1 || x > A || y < 1 || y > B) {
                cout << "Robot " << r << " crashes into the wall";
                check = true;
                return;
            }
            
            if (ground[x][y][0] != 0) {
                cout << "Robot " << r << " crashes into robot " << ground[x][y][0];
                check = true;
                return;
            }
        }

        ground[x][y][0] = r;
        ground[x][y][1] = d;
        robot[r][0] = x;
        robot[r][1] = y;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> B >> A >> N >> M;

    int x, y;
    char d;
    for (int i = 1; i <= N; i++) {
        cin >> y >> x >> d;

        ground[x][y][0] = i;
        
        if (d == 'N') {
            ground[x][y][1] = 0;
        } else if (d == 'E') {
            ground[x][y][1] = 1;
        }
        else if (d == 'S') {
            ground[x][y][1] = 2;
        }
        else {
            ground[x][y][1] = 3;
        }

        robot[i][0] = x;
        robot[i][1] = y;
    }

    int r, n;
    char c;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> n;

        if (check) {
            continue;
        }
        Command(r, c, n);
    }

    if (!check) {
        cout << "OK";
    }
    
    return 0;
}