// BOJ 1561 - 놀이 공원
#include <iostream>
#include <vector>
using namespace std;
const long long MAX_PERSON = 2e9;
const long long MAX_TIME = 30;

long long searchTime(vector<int>& rides, int n, int m) {
    long long time = -1;
    long long start = 0;
    long long end = MAX_PERSON * MAX_TIME;
    while (start <= end) {
        long long mid = (start + end) / 2;
        long long person = m;
        for (int i = 0; i < m; i++) {
            person += mid / rides[i];
        }
        if (person >= n) {
            time = mid;
            end = mid - 1;
        } else start = mid + 1;
    }
    return time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> rides(m);
    for (int i = 0; i < m; i++) {
        cin >> rides[i];
    }
    
    if (m >= n) cout << n << '\n';
    else {
        long long time = searchTime(rides, n, m);
        // time - 1 분까지 탄 사람의 수를 구하기
        long long person = m;
        for (int i = 0; i < m; i++) {
            person += (time - 1) / rides[i];
        }
        // time 분에 탄 사람중에서 마지막 사람이 탄 놀이기구 번호 찾기
        for (int i = 0; i < m; i++) {
            if (time % rides[i] == 0) person++;
            if (person == n) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
    
    return 0;
}
