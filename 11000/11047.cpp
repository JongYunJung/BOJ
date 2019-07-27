// BOJ 11047 - 동전0
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        if (k < a[i]) continue;
        ans += (k / a[i]);
        k %= a[i];
    }
    
    cout << ans << '\n';
    return 0;
}

// 다시 풀어봄.. 190727(토)
// 백준 사이트가 다운되서 돌려보지 못함 나중에 돌려볼 것
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    int n, k;
//    cin >> n >> k;
//
//    vector<int> coins;
//    for (int i = 0; i< n; i++) {
//        int value;
//        cin >> value;
//        if (value <= k) {
//            coins.push_back(value);
//        }
//    }
//
//    int answer = 0;
//    for (size_t i = coins.size()-1; i >= 0; i--) {
//        if (k == 0) break;
//        if (k >= coins[i]) {
//            answer += k / coins[i];
//            k %= coins[i];
//        }
//    }
//
//    cout << answer << '\n';
//    return 0;
//}
