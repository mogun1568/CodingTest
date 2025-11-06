#include <iostream>
#include <string>
using namespace std;

string str;
int len;
int used[100];

void DFS(int start, int end) {
    char minC = 'Z' + 1;
    int idx = -1;
    for (int i = start; i < end; i++) {
        if (str[i] < minC) {
            minC = str[i];
            idx = i;
        }
    }

    if (idx == -1)
        return;

    used[idx] = true;
    for (int i = 0; i < len; i++) {
        if (used[i])
            cout << str[i];
    }
    cout << '\n';

    DFS(idx + 1, end);
    DFS(start, idx);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    len = str.length();

    DFS(0, len);
    
    return 0;
}