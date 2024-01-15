#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int box[100][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int l, w, n, dir, dis, cnt = 0;
    cin >> l >> w >> n;

    for (int i = 0; i < n; i++) {
        cin >> box[i][0] >> box[i][1];
    }

    cin >> dir >> dis;

    for (int i = 0; i  <n; i++) {
        if (dir == 1) {
            if (box[i][0] == 1) {
                cnt += abs(dis - box[i][1]);
            } else if (box[i][0] == 2) {
                cnt += w + min(dis + box[i][1], 2 * l - (dis + box[i][1])); 
            } else if (box[i][0] == 3) {
                cnt += dis + box[i][1];
            } else {
                cnt += (l - dis) + box[i][1];
            }
        } else if (dir == 2) {
            if (box[i][0] == 1) {
                cnt += w + min(dis + box[i][1], 2 * l - (dis + box[i][1])); 
            } else if (box[i][0] == 2) {
                cnt += abs(dis - box[i][1]);
            } else if (box[i][0] == 3) {
                cnt += dis + (w - box[i][1]);
            } else {
                cnt += (l - dis) + (w - box[i][1]);
            }
        } else if (dir == 3) {
            if (box[i][0] == 1) {
                cnt += dis + box[i][1];
            } else if (box[i][0] == 2) {
                cnt += (w - dis) + box[i][1];
            } else if (box[i][0] == 3) {
                cnt += abs(dis - box[i][1]);
            } else {
                cnt += l + min(dis + box[i][1], 2 * w - (dis + box[i][1])); 
            }
        } else {
           if (box[i][0] == 1) {
            cnt += dis + (l - box[i][1]);
            } else if (box[i][0] == 2) {
                cnt += (w - dis) + (l - box[i][1]);
            } else if (box[i][0] == 3) {
                cnt += l + min(dis + box[i][1], 2 * w - (dis + box[i][1])); 
            } else {
                cnt += abs(dis - box[i][1]);
            } 
        }
    }

    cout << cnt;
    
    return 0;
}