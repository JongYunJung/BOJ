// BOJ 2805 - 나무 자르기
// 이분 탐색
// 이분 탐색을 통해 중간 지점은 현재 절단기에서 설정할 수 있는 높이가 된다.
// N 만큼 나무를 자르고 난 뒤의 합을 통해 이분 탐색할 위치를 정하면 된다.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> woods(n);
    for (int i = 0; i < n; i++) {
        cin >> woods[i];
    }
    
    long long answer = 0;
    long long low = 1, high = *max_element(woods.begin(), woods.end());
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (mid > woods[i]) continue;
            sum += woods[i] - mid;
        }
        
        if (sum >= m) {
            answer = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    
    cout << answer << '\n';
    return 0;
}
