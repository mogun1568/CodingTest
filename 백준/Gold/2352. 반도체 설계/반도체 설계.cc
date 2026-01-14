#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> ports;
    int p;
    cin >> p;
    ports.push_back(p);
    
    while (--N) {
        cin >> p;

        if (p < ports.back()) {
            auto it = lower_bound(ports.begin(), ports.end(), p);
            *it = p;
        }
        else
            ports.push_back(p);
    }

    cout << ports.size();
    
    return 0;
}