// BOJ 11399 - ATM
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<int> pSum(n+1);
    vector<bool> check(n+1);
    for (int i = 1; i <= n; i++) {
        int minIndex = 0;
        int minValue = 1000;
        for (int j = 1; j <= n; j++) {
            if (check[j]) continue;
            if (minValue > a[j]) {
                minValue = a[j];
                minIndex = j;
            }
        }
        check[minIndex] = true;
        pSum[i] = pSum[i-1] + minValue;
    }
    
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += pSum[i];
    cout << sum << '\n';
    
    return 0;
}

// BOJ 11399 - ATM
// 190730 - 두 번째 풀이
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int temp = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        temp += arr[i];
        answer += temp;
    }
    
    cout << answer << '\n';
    return 0;
}
