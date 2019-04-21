// BOJ 1965 - 상자 넣기
// 비슷한 유형
// 11053 - 가장 긴 증가하는 부분 수열
// 11722 - 가장 긴 감소하는 부분 수열
// 11055 - 가장 큰 증가하는 부분 수열
// 11054 - 가장 긴 바이토닉 부분 수열
#include <iostream>
#include <vector>
using namespace std;
int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    dp[0] = 1;
    int max = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        if (max < dp[i]) {
            max = dp[i];
        }
    }
    
    cout << max << '\n';
    return 0;
}

