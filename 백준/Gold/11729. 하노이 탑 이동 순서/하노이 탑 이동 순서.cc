#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void hanoi(int n, int start, int mid, int end){
    if(n == 1){
        cout << start << " " << end << "\n";
        return;
    }
    
    hanoi(n - 1, start, end, mid);
    cout << start << " " << end << "\n";
    hanoi(n - 1, mid, start, end);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    string k = to_string(pow(2, n));
    int idx = k.find('.');
    k = k.substr(0, idx);
    k[k.length() - 1] -= 1;	
    cout << k << "\n";

    hanoi(n, 1, 2, 3);
    
    return 0;
}