#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string n;
    cin >> n;
    
    int arr[10] = {0};
 
    for(int i = 0; i < n.length(); i++){
        arr[n[i] - '0']++;
    }
 
    int num = 0;
    for(int i = 0; i < 10; i++){
        if(i != 6 && i != 9) {
            num = max(num, arr[i]);
        }
    }
    
    cout << max(num, (arr[6] + arr[9] + 1) / 2);

    return 0;
}