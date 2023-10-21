#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int save[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> save[i];
    }
    
    sort(save, save + n);
    
    for (int i = 0; i < n; i++) {
        cout << save[i] << '\n';
    }
    
    return 0;
}