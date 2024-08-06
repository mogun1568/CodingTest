#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
pair<int, int> jewelry[300000];
int bag[300000];

void Solution() {
    sort(jewelry, jewelry + N);
    sort(bag, bag + K);
    
    priority_queue<int> pq;
    long long sum = 0;
    int idx = 0;
    
    for (int i = 0; i < K; i++) {
        int weight = bag[i];

        for (int j = idx; j < N; j++) {
            int m = jewelry[j].first;
            int v = jewelry[j].second;
            
            if (m > weight)
                break;

            pq.push(v);
            idx++;
        }

        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;

    int m, v;
    for (int i = 0; i < N; i++) {
        cin >> m >> v;
        jewelry[i].first = m;
        jewelry[i].second = v;
    }
    for (int i = 0; i < K; i++) {
        cin >> bag[i];
    } 

    Solution();
    
    return 0;
}