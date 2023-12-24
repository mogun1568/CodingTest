#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1004000

bool num[MAX];

void prime() {
    num[1] = true;
    for (int i = 2; i <= MAX; i++) {
        if (!num[i]) {
            for (int j = i + i; j <= MAX; j += i) {
                num[j] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    prime();

    while (1) {
        if (num[n]) {
            n++;
            continue;
        }

        string str1 = to_string(n), str2 = str1;
        reverse(str1.begin(), str1.end());

        if (str1 != str2) {
            n++;
            continue;
        }

        cout << n;
        break;
    }
    
    return 0;
}