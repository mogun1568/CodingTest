#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    string str;
    cin >> str;

    vector<char> v;
    for (int i = 0; i < N; i++) {
        while (!v.empty() && str[i] > v.back() && K > 0) {
            v.pop_back();
            K--;
        }
        v.push_back(str[i]);
    }

    while (K--)
        v.pop_back();

    for (char c : v)
        cout << c;
    
    return 0;
}