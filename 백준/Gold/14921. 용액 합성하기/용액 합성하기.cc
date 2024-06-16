#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
 
    vector<int> vec;
    vec.resize(n);
 
    for (int& ele : vec) cin >> ele;
 
    int ans = INT_MAX;
 
    // 투 포인터 사용
    int s = 0;
    int e = n - 1;
 
    // s와 e는 겹쳐서는 안된다.
    while (s < e)
    {
        // 용액의 합을 구하기
        int value = vec[s] + vec[e];
 
        // value가 0보다 작다면 s를 오른쪽으로 밀어 
        // 0에 근접하도록 해준다
        if (value <= 0)
        {
            // 0에 얼마나 가까운지는 절대값을 이용하여 비교한다.
            if (abs(value) < abs(ans)) ans = value;
            s++;
        }
        // value가 0보다 크다면 e를 왼쪽으로 밀어 
        // 0에 근접하도록 해준다.
        else if (value > 0)
        {
            if (abs(value) < abs(ans)) ans = value;
            e--;
        }
    }
 
    cout << ans;
 
 
    return 0;
}