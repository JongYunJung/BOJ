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
    
    vector<int> target(n);
    for (int i = 0; i < n; i++) {
        cin >> target[i];
    }
    
    sort(target.begin(), target.end());
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        
        bool find = false;
        int start = 0, end = (int)target.size();
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target[mid] < value) {
                start = mid + 1;
            } else if (target[mid] > value) {
                end = mid - 1;
            } else {
                find = true;
                break;
            }
        }
        
        cout << find << '\n';
    }
    
    return 0;
}
