#include <iostream>

using namespace std;

int N;
char c[3] = {'m', 'o', 'o'};

void Dfs(int n, int k, int len) {
    if (n <= 3){
        cout << c[n - 1];
        return;
    }
    
    int newLen = len * 2 + k + 3;
    
    if (newLen < n){
        Dfs(n, k+1, newLen);
    }
    else{
        if (n > len && n <= len + k + 3) {
            if(n - len != 1)
                cout << "o";
            else
                cout << "m";
            return;
        }
        else {
            Dfs(n - (len + k + 3), 1, 3);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    Dfs(N, 1, 3);
    
    return 0;
}