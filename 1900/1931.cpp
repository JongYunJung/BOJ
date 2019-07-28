// BOJ 1931 - 회의실 배정
// 그리디 알고리즘 문제
// 끝나는 시간을 기준으로 졍렬하게 되면 제일 빨리 끝나는 시간이 앞에 오게 되므로
// 회의실 배정을 최대로 할 수 있다.
// 회의를 종료시간을 저장하는 변수를 선언한다. (standardEndTime)
// 다음 회의 시작 시간이 현재 회의를 종료하는 시간(standardEndTime)보다 크거나 같으면,
// 회의를 종료시간을 저장하는 변수를 현재 회의를 종료하는 시간으로 갱신한다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int> > time(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i].second >> time[i].first;
    }
    
    // 끝나는 시간 기준으로 정렬
    sort(time.begin(), time.end());
    
    int standardEndTime = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int startTime = time[i].second;
        int endTime = time[i].first;
        if (standardEndTime <= startTime) {
            standardEndTime = endTime;
            ans++;
        }
    }
    
    cout << ans << '\n';
    return 0;
}

// 두 번째로 풀어본 코드
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<int, int> > arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    
    sort(arr.begin(), arr.end());
    
    int answer = 1;
    int endTime = arr[0].first;
    for (int i = 1; i < n; i++) {
        if (endTime > arr[i].second) continue;
        endTime = arr[i].first;
        answer++;
    }
    
    cout << answer << '\n';
    return 0;
}
