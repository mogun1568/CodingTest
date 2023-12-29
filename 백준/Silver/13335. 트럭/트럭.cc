#include <iostream>
#include <queue>

using namespace std;

int truck[1000];

int main() {
    int n, w, l, cnt = 0;
    cin >> n >> w >> l;

    queue<int> q;
    int weight = 0;
    for(int i = 0; i < n; i++) {
        cin >> truck[i];
        
        while(true) {
            if(q.size() == w) {
                weight -= q.front(); // 맨 앞의 트럭 제거
                q.pop();
            }
            if(weight + truck[i] <= l) {
                weight += truck[i];
                break;
            }
            q.push(0); // 무게가 l을 넘는 경우
            cnt++;
        }
        
        q.push(truck[i]);
        cnt++;
    }
    
    cout << cnt + w;
    
    return 0;
}