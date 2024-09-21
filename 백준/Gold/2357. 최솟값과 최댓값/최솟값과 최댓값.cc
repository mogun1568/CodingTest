#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1000000001

int N, M;
int arr[100001];
pair<int, int> segTree[400004];

pair<int, int> Init(int node, int start, int end) {
    if (start == end)
        return segTree[node] = {arr[start], arr[start]};

    int mid = (start + end) / 2;
    pair<int, int> a = Init(node * 2, start, mid);
    pair<int, int> b = Init(node * 2 + 1, mid + 1, end);

    return segTree[node] = {min(a.first, b.first), max(a.second, b.second)};
}

pair<int, int> MinMax(int node, int start, int end, int left, int right) {
    // [left,right]와 [start,end]가 겹치지 않는 경우
    if (left > end || right < start)
        return {INF, 0};

    // [left,right]가 [start,end]를 완전히 포함하는 경우
    if (left <= start && end <= right)
        return segTree[node];

    // [start,end]가 [left,right]를 완전히 포함하는 경우
    // [left,right]와 [start,end]가 겹쳐져 있는 경우
    int mid = (start + end) / 2;
    pair<int, int> a = MinMax(node * 2, start, mid, left, right);
    pair<int, int> b = MinMax(node * 2 + 1, mid + 1, end, left, right);
    
    return {min(a.first, b.first), max(a.second, b.second)};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    Init(1, 1, N);

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        pair<int, int> result = MinMax(1, 1, N, a, b);
        cout << result.first << " " << result.second << "\n";
    }
    
    return 0;
}