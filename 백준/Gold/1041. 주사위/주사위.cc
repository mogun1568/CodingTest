#include <iostream>
#include <algorithm>

using namespace std;

int dice[6];

int minThree() {
    int result = 151;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 6; k++) {
                if (i + j == 5 || i + k == 5 || j + k == 5) {
                    continue;
                }

                result = min(result, dice[i] + dice[j] + dice[k]);
            }
        }
    }

    return result;
}

int minTwo() {
    int result = 101;

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (i + j == 5) {
                continue;
            }

            result = min(result, dice[i] + dice[j]);
        }
    }

    return result;
}

int minOne() {
    int result = *min_element(dice, dice + 6);

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, a, b, c, answer = 0;
    
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> dice[i];
    }

    if (n == 1) {
        for (int i = 0; i < 6; i++) {
            answer += dice[i];
        }
        answer -= *max_element(dice, dice + 6);
            
        cout << answer;
        
        return 0 ;
    }

    a = 4;
    b = 4 * (2 * n - 3);
    c = n * n * 5 - (a * 3 + b * 2);

    answer += a * minThree();
    answer += b * minTwo();
    answer += c * minOne();

    cout << answer;
    
    return 0;
}