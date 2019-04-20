// BOJ 1038 - 감소하는 수
// 생각보다 조건이 까다롭다.
// 범위도 잘 생각해서 지정해야하고
// n 이 1000000 의 제한을 가지고 있어서 헷갈렸던 문제
// 해결 방법은 생각했지만 구현에서 까다로웠음
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    const int MAX = 1000000;
    vector<long long> decreaseNums(MAX+1);
    queue<long long> q;
    for (int i = 1; i <= 9; i++) {
        q.push(i);
        decreaseNums[i] = i;
    }
    
    int idx = 9;
    while (idx <= n) {
        if (q.empty()) break;
        
        long long decreaseNum = q.front();
        q.pop();
        
        int lastNum = decreaseNum % 10;
        for (int i = 0; i < lastNum; i++) {
            q.push(decreaseNum * 10 + i);
            decreaseNums[++idx] = decreaseNum * 10 + i;
        }
    }
    
    if (decreaseNums[n] == 0 && n) {
        cout << -1 << '\n';
    } else {
        cout << decreaseNums[n] << '\n';
    }
    
    return 0;
}
