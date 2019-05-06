// BOJ 2565 - 전깃줄
// lower_bound(이분 탐색)을 활용한 LIS 알고리즘으로 해결하기
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100;
pair<int, int> p[MAX];
int lis[MAX];

int my_lower_bound(int lis_index, int target) {
    int start = 0, end = lis_index;
    while (start < end) {
        int mid = (start + end) / 2;
        if (lis[mid] < target) start = mid + 1;
        else end = mid;
    }
    return end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    
    sort(p, p+n);
    
    int j = 0;
    lis[j] = p[j].second;
    for (int i = 1; i < n; i++) {
        if (lis[j] < p[i].second) {
            lis[++j] = p[i].second;
        } else {
            int ii = my_lower_bound(j, p[i].second);
            lis[ii] = p[i].second;
        }
    }
    
    cout << n - (j + 1) << '\n';
    return 0;
}

