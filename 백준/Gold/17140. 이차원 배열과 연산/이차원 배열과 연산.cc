#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101][101];
unordered_map<int, int> um;

bool cmp(const int& a, const int& b) {
    if (um[a] == um[b])
        return a < b;
    return um[a] < um[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c, k;
    cin >> r >> c >> k;

    int a = 3, b = 3;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++)
            cin >> arr[i][j];
    }

    int ans = 0;
    while (ans < 101) {
        if (arr[r][c] == k) {
            cout << ans;
            return 0;
        }

        if (a >= b) {
            int maxL = 1;
            for (int i = 1; i <= a; i++) {
                um.clear();
                
                for (int j = 1; j <= b; j++) {
                    if (arr[i][j] != 0)
                        um[arr[i][j]]++;
                }

                vector<int> v;
                for (const auto& [key, value] : um)
                    v.push_back(key);
                sort(v.begin(), v.end(), cmp);

                int l = 1;
                for (int j = 0; j < v.size(); j++) {
                    if (l > 100) {
                        l = 100;
                        break;
                    }
                    
                    arr[i][l++] = v[j];
                    arr[i][l++] = um[v[j]];
                }

                for (int j = l; j <= b; j++)
                    arr[i][j] = 0;

                maxL = max(maxL, l - 1);
            }

            b = maxL;
        }
        else {
            int maxL = 1;
            for (int i = 1; i <= b; i++) {
                um.clear();
                
                for (int j = 1; j <= a; j++) {
                    if (arr[j][i] != 0)
                        um[arr[j][i]]++;
                }

                vector<int> v;
                for (const auto& [key, value] : um)
                    v.push_back(key);
                sort(v.begin(), v.end(), cmp);

                int l = 1;
                for (int j = 0; j < v.size(); j++) {
                    if (l > 100) {
                        l = 100;
                        break;
                    }
                    
                    arr[l++][i] = v[j];
                    arr[l++][i] = um[v[j]];
                }

                for (int j = l; j <= a; j++)
                    arr[j][i] = 0;

                maxL = max(maxL, l - 1);
            }

            a = maxL;
        }

        ans++;
    }

    if (ans > 100)
        cout << -1;
    else
        cout << ans;
    
    return 0;
}