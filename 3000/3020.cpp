// BOJ 3020 - 개똥벌레
// 부분합을 이용해서 해결할 수 있다.
// a 배열은 석순을 길이별로 구분한 것
// 석순은 큰 길이가 작은 길이를 포함하고 있다는 특징
// b 배열은 종유석을 길이별로 구분한 것
// 종유석은 매달려 있는 길이가 작을수록 큰 길이를 포함하고 있는 특징
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, h;
    cin >> n >> h;
    vector<int> a(h+1), b(h+1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        if (i % 2 == 1) {
            a[k]++;
        } else {
            b[h-k+1]++;
        }
    }
    
    for (int i = 1; i <= h; i++) {
        b[i] += b[i-1];
    }
    
    for (int i = h-1; i >= 1; i--) {
        a[i] += a[i+1];
    }
    
    for (int i = 1; i <= h; i++) {
        a[i] += b[i];
    }
    
    sort(a.begin(), a.end());
    
    int cnt = 1;
    for (int i = 2; i <= h; i++) {
        if (a[1] == a[i]) cnt++;
        else break;
    }
    
    cout << a[1] << " " << cnt << '\n';
    return 0;
}
