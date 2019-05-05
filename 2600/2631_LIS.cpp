// BOJ 2631 - 줄세우기
// LIS 문제
// O(NlogN) 방식
#include <iostream>
#include <vector>
using namespace std;
int dp[200];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> lis(n);
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        int target;
        cin >> target;
        
        if (i == 0) lis[i] = target;
        else {
            if (lis[j] < target) {
                lis[++j] = target;
            } else {
                int left = 0, right = j;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (lis[mid] < target) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                lis[right] = target;
            }
        }
    }
    
    cout << n - (j + 1) << '\n';
    return 0;
}

