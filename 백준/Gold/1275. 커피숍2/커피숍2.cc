#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
long long segment[400004];

long long Init(int node, int start, int end) {
    if (start == end)
        return segment[node] = arr[start];

    int mid = (start + end) / 2;
    return segment[node] = Init(node * 2, start, mid) + Init(node * 2 + 1, mid + 1, end);
}

void Update(int node, int start, int end, int index, int value) {
    if (index < start || index > end)
        return;

    if (start == end) {
        segment[node] = value;
        return;
    }

    int mid = (start + end) / 2;
    Update(node * 2, start, mid, index, value);
    Update(node * 2 + 1, mid + 1, end, index, value);
    segment[node] = segment[node * 2] + segment[node * 2 + 1];
}

long long Sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return 0;

    if (left <= start && right >= end)
        return segment[node];

    int mid = (start + end) / 2;
    return Sum(node * 2, start, mid, left, right) + Sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    Init(1, 1, N);

    int x, y, a, b;
    while (Q--) {
        cin >> x >> y >> a >> b;

        if (x > y)
            swap(x, y);
        
        cout << Sum(1, 1, N, x, y) << "\n";
        Update(1, 1, N, a, b);
    }
    
    return 0;
}