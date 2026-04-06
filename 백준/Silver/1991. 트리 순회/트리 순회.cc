#include <iostream>
using namespace std;

int N;
pair<char, char> tree[26];

void Pre(char cur) {
    if (cur == '.')
        return;

    cout << cur;
    Pre(tree[cur - 'A'].first);
    Pre(tree[cur - 'A'].second);
}

void In(char cur) {
    if (cur == '.')
        return;

    In(tree[cur - 'A'].first);
    cout << cur;
    In(tree[cur - 'A'].second);
}

void Post(char cur) {
    if (cur == '.')
        return;

    Post(tree[cur - 'A'].first);
    Post(tree[cur - 'A'].second);
    cout << cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    char node;
    for (int i = 0; i < N; i++)
        cin >> node >> tree[node - 'A'].first >> tree[node - 'A'].second;

    Pre('A');
    cout << "\n";
    In('A');
    cout << "\n";
    Post('A');
    
    return 0;
}