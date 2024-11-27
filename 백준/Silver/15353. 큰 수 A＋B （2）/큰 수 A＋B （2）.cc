#include <iostream>
#include <string>
using namespace std;

int arr[10005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.length(); i++)
        arr[i] = a[a.length() - i - 1] - '0';

    for (int i = 0; i < b.length(); i++) {
        int j = i;
        arr[i] += b[b.length() - i - 1] - '0';

        while (arr[j] > 9) {
            arr[j + 1] += arr[j] / 10;
            arr[j] %= 10;
            j++;
        }
    }

    string ans = "";
    bool flag = false;
    for (int i = 10004; i >= 0; i--) {
        if (arr[i] != 0)
            flag = true;

        if (!flag)
            continue;

        ans += arr[i] + '0';
    }

    cout << ans;
    
    return 0;
}