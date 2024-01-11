#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rec[101];
int order[101];

bool cmp(int a, int b) {
    if (rec[a] == rec[b]) {
        return order[a] > order[b];
    }
    return rec[a] < rec[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, allRec, num;
    cin >> n >> allRec;

    vector<int> frame;
    bool exist;
    for (int i = allRec; i > 0; i--) {
        cin >> num;

        rec[num]++;

        exist = false;
        if (rec[num] == 1) {
            order[num] = i;
        } else {
            exist = true;
        }

        if (!exist) {
            if (frame.size() >= n) {
                sort(frame.begin(), frame.end(), cmp);
                
                rec[frame.front()] = 0;
                order[frame.front()] = 0;
                frame.front() = num;
            } else {
                frame.push_back(num);
            }
        }
    }

    sort(frame.begin(), frame.end());
    
    for (auto f : frame) {
        cout << f << " ";
    }
    
    return 0;
}