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

// 이분 탐색 풀이
// lower_bound, upper_bound 직접 구현해봄
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int my_lower_bound(vector<int>& arr, int key) {
    int start = 0, end = (int)arr.size();
    while (start < end) {
        int mid = (start + end) / 2;
        if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return end;
}

int my_upper_bound(vector<int>& arr, int key) {
    int start = 0, end = (int)arr.size();
    while (start < end) {
        int mid = (start + end) / 2;
        if (arr[mid] <= key) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, h;
    cin >> n >> h;
    
    vector<int> bot(n/2), top(n/2);
    for (int i = 0; i < n/2; i++) {
        cin >> bot[i] >> top[i];
    }
    
    sort(bot.begin(), bot.end());
    sort(top.begin(), top.end());
    
    int answer = n, cnt = 0;
    for (int i = 1; i <= h; i++) {
        int temp = (int)bot.size() - my_lower_bound(bot, i);
        temp += (int)top.size() - my_upper_bound(top, h - i);
        
        if (answer == temp) cnt++;
        else if (answer > temp) {
            answer = temp;
            cnt = 1;
        }
    }
    
    cout << answer << " " << cnt << '\n';
    return 0;
}
