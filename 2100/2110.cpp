// BOJ 2110 - 공유기 설치
// 해결하지 못해서 블로그를 참고..
// parametric search -> binary search의 응용
// parametric search ? 탐색을 통해 최적의 해를 찾는 방법
// 이분 탐색 응용에 대해 더 풀어보자.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    int ans = 0;
    int left = 1;
    int right = a[n-1] - a[0];
    while (left <= right) {
        int gap = (left + right) / 2;
        int std_house = a[0];   // 첫 번째 집을 기준
        int temp_c = 1;         // 첫 번째 집에 공유기를 설치
        
        for (int i = 1; i < n; i++) {
            if (a[i] - std_house >= gap) {
                std_house = a[i];
                ++temp_c;
            }
        }
        
        if (temp_c >= c) {
            ans = gap;
            left = gap + 1;
        } else {
            right = gap - 1;
        }
    }
    
    cout << ans << '\n';
    return 0;
}

