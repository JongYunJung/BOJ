// BOJ 1920 - 수 찾기
// 기본적인 이분 탐색 방법으로 해결 했다.
// 이분 탐색할 배열을 정렬해주는 것은 필수이다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int m;
    cin >> m;
    sort(a.begin(), a.end());
    while (m--) {
        int value;
        cin >> value;
        
        bool find = false;
        int left = 0, right = (int)a.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (a[mid] > value) {
                right = mid - 1;
            } else if (a[mid] < value) {
                left = mid + 1;
            } else {
                find = true;
                break;
            }
        }
        
        cout << find << '\n';
    }
    
    return 0;
}
