#include <iostream>

using namespace std;

long long N, M, K;
long long arr[1000001];
long long segTree[4000004];

long long Init(int node, int start, int end) {
    if (start == end)    // 노드가 리프 노드인 경우
        return segTree[node] = arr[start];    // 배열의 그 원소를 가져야 함

    int mid = (start + end) / 2;

    return segTree[node] = Init(node * 2, start, mid) + Init(node * 2 + 1, mid + 1, end);
}

void Update(int node, int start, int end, int index, long long diff) {
    // [start, end]에 index가 포함되지 않는 경우
    if (index < start || index > end)
        return;

    // [start, end]에 index가 포함되는 경우
    segTree[node] += diff;

    // 리프 노드인지 검사를 하고 아래 자식 노드를 갱신해준다.
    if (start != end) {
        int mid = (start + end) / 2;
        Update(node * 2, start, mid, index, diff);
        Update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

long long Sum(int node, int start, int end, int left, int right) {
    // [left,right]와 [start,end]가 겹치지 않는 경우
    if (left > end || right < start)
        return 0;

    // [left,right]가 [start,end]를 완전히 포함하는 경우
    if (left <= start && end <= right)
        return segTree[node];

    // [start,end]가 [left,right]를 완전히 포함하는 경우
    // [left,right]와 [start,end]가 겹쳐져 있는 경우
    int mid = (start + end) / 2;
    return Sum(node * 2, start, mid, left, right) + Sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    Init(1, 1, N);

    long long a, b, c;
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;

        if (a == 1) {
            long long diff = c - arr[b];
            arr[b] = c;
            Update(1, 1, N, b, diff);
        }
        else {
            cout << Sum(1, 1, N, b, c) << "\n";
        }
    }
    
    return 0;
}