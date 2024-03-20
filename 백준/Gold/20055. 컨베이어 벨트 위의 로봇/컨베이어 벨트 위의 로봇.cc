#include <iostream>
#include <queue>

using namespace std;

int n, k, Start, End, cnt, result;
int belt[201];
bool isRobot[201];
queue<int> q;

void moveBelt() {
    Start--;
    End--;
    if (Start < 1) { Start = 2 * n; }
    if (End < 1) { End = 2 * n; }
}

void moveRobot() {
    int Size = q.size();
    for (int i = 0; i < Size; i++) {
        int cur = q.front();
        isRobot[cur] = false;
        q.pop();

        if (cur == End) {
            continue;
        }

        int next = cur + 1;
        if (next > 2 * n) {
            next = 1;
        }

        if (!isRobot[next] && belt[next] > 0) {
            belt[next]--;
            if (belt[next] < 1) {
                cnt++;
            }

            if (next == End) {
                continue;
            }
            
            isRobot[next] = true;
            q.push(next);
        } else {
            isRobot[cur] = true;
            q.push(cur);
        }
    }
}

void makeRobot() {
    if (!isRobot[Start] && belt[Start] > 0) {
        belt[Start]--;
        if (belt[Start] < 1) {
            cnt++;
        }
    
        isRobot[Start] = true;
        q.push(Start);
    }    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> belt[i];
    }

    Start = 1;
    End = n;
    while (cnt < k) {
        moveBelt();
        moveRobot();
        makeRobot();
        result++;
    }

    cout << result;

    return 0;
}