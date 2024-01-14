#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[2000001];

int main() {
    
    
    int n, s;
    cin >> n;

    vector<int> v = {0};
    for (int i = 0; i < n; i++) {
        cin >> s;
        int size = v.size();

        for (int j = 0; j < size; j++) {
            if (!visited[s + v[j]]) {
                v.push_back(s + v[j]);
                visited[s + v[j]] = true;
            }
        }
    }

    sort(v.begin(), v.end());

    int i;
    for (i = 1; i < v.size(); i++) {
        if (i != v[i]) {
            cout << i;
            break;
        }
    }
    if (i == v.size()) {
        cout << i;
    }
    
    return 0;
}