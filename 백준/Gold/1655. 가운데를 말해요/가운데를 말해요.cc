#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, num;
    priority_queue<int> frontPQ;
    priority_queue<int, vector<int>, greater<int>> backPQ;
    
    cin >> N >> num;
    frontPQ.push(num);
    cout << num << "\n";
    N--;
    
    while (N--) {
        cin >> num;

        if (num <= frontPQ.top()) {
            frontPQ.push(num);

            if (frontPQ.size() - backPQ.size() > 1) {
                backPQ.push(frontPQ.top());
                frontPQ.pop();
            }
        }
        else {
            backPQ.push(num);

            if (backPQ.size() > frontPQ.size()) {
                frontPQ.push(backPQ.top());
                backPQ.pop();
            }
        } 

        cout << frontPQ.top() << "\n";
    }
    
    return 0;
}