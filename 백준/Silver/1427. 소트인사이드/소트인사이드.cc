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
    
    sort(n.begin(), n.end(), greater<char>());
    
    cout << n << '\n';

    return 0;
}