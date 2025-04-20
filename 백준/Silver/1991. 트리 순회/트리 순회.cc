#include <iostream>
using namespace std;

char tree[26][2];

void Pre(char cur) {
    if (cur == '.')
        return;
    
    cout << cur;
    Pre(tree[cur - 'A'][0]);
    Pre(tree[cur - 'A'][1]);
}

void In(char cur) {
    if (cur == '.')
        return;
    
    In(tree[cur - 'A'][0]);
    cout << cur;
    In(tree[cur - 'A'][1]);
}

void Post(char cur) {
    if (cur == '.')
        return;
    
    Post(tree[cur - 'A'][0]);
    Post(tree[cur - 'A'][1]);
    cout << cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    char root;
    for (int i = 0; i < N; i++)
        cin >> root >> tree[root - 'A'][0] >> tree[root - 'A'][1];
        
    Pre('A');
    cout << "\n";
    In('A');
    cout << "\n";
    Post('A');
    
    return 0;
}