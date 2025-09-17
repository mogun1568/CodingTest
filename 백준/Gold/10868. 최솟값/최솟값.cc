#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000001

int arr[100001];
int segment[400004];

int Init(int node, int start, int end) {
    if (start == end)
        return segment[node] = arr[start];

    int mid = (start + end) / 2;
    return segment[node] = min(Init(node * 2, start, mid), Init(node * 2 + 1, mid + 1, end));
}

int MinMax(int node, int start, int end, int left, int right) {
    // [left,right]와 [start,end]가 겹치지 않는 경우
    if (left > end || right < start)
        return INF;

    // [left,right]가 [start,end]를 완전히 포함하는 경우
    if (left <= start && end <= right)
        return segment[node];

    // [start,end]가 [left,right]를 완전히 포함하는 경우
    // [left,right]와 [start,end]가 겹쳐져 있는 경우
    int mid = (start + end) / 2;
    return min(MinMax(node * 2, start, mid, left, right), MinMax(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    Init(1, 1, N);
    
    int a, b;
    while (M--) {
        cin >> a >> b;
        cout << MinMax(1, 1, N, a, b) << "\n";
    }
    
    return 0;
}