#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Judge
{
    int age;
    string name;
};

bool cmp(const Judge &a, const Judge &b) {
    return a.age < b.age;
}

int main()
{
    // 입출력 시간 단축
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    Judge judge[100001];
    for (int i = 0; i < n; i++) {
        cin >> judge[i].age >> judge[i].name;
    }
    
    // 기존 순서를 보장하는 정렬 함수
    stable_sort(judge, judge + n, cmp);
    
    for (int i = 0; i < n; i++) {
        cout << judge[i].age << " " << judge[i].name << '\n';
    }
}