#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;

int BinarySearch(int a) {
    int start = 0, end = arr.size() - 1, mid;

    while (start < end) {
        mid = (start + end) / 2;

        if (arr[mid] < a)
            start = mid + 1;
        else
            end = mid;
    }

    return end;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    int a, idx;
    cin >> a;
    arr.push_back(a);
    
    for (int i = 1; i < N; i++) {
        cin >> a;

        if (a > arr.back())
            arr.push_back(a);
        else {
            idx = BinarySearch(a);
            arr[idx] = a;
        }
    }

    cout << arr.size();

    return 0;
}