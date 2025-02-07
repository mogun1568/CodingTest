#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str[50];

bool cmp(const string &a, const string &b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }

    int sumA = 0, sumB = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] >= '0' && a[i] <= '9')
            sumA += a[i] - '0';
        if (b[i] >= '0' && b[i] <= '9')
            sumB += b[i] - '0';
    }

    if (sumA != sumB)
        return sumA < sumB;

    return a < b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    string s;
    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }

    sort(str, str + N, cmp);

    for (int i = 0; i < N; i++)
        cout << str[i] << "\n";
    
    return 0;
}