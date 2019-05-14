// BOJ 1744 - 수 묶기
// 그리디 알고리즘
// 처음 풀이를 시작했을땐 단순한 루프에서 분기문으로 그리디 알고리즘을 처리하면 된다고 생각했으나
// 여러 조건들이 존재하는 문제였다.
// 1) 숫자에서 1이 있는 경우에는 곱하는 경우보다 더하는 경우가 더 크다. (1 이면 그냥 갯수에서 +1 하기)
// 2) 양수, 음수를 관리하는 자료구조를 생각해야 한다. (우선순위 큐를 이용해서 한다.)
//      우선순위 큐를 이용하는 이유?? 말 그대로 NlogN 이라는 시간을 통해 우선순위 높은 값을 추출할 수 있기 때문에
// 3) 우선순위 큐가 갯수가 홀수일때의 경우도 생각해야한다.
// 4) 더하기 보다 곱셈이 최댓값을 만들 확률이 크다는 그리디한 생각을 해야한다.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    priority_queue<int, vector<int>, greater<int> >  negative;
    priority_queue<int> positive;
    
    int n;
    cin >> n;
    
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 1) one++;
        else if (num == 0) zero++;
        else if (num < 0) negative.push(num);
        else if (num > 0) positive.push(num);
    }
    
    // 예외 상황 처리 - 큐의 개수가 홀수 인 경우
    // 짝을 맞춰 주어야 한다.
    if (positive.size() % 2 == 1) {
        positive.push(1);
    }
    
    if (negative.size() % 2 == 1) {
        // 0이 있다? (해당 숫자 * 0) 이므로 최대값을 구할 수 있다.
        // 0이 없다? 1을 넣어서 줘야 한다.
        (zero == 0) ? negative.push(1) : negative.push(0);
    }
    
    int sum = 0;
    // 무조건 두 수를 곱한다고 가정한다.
    // 두 수를 곱해야만 최대 나올 확률이 크기 때문에
    while (!negative.empty()) {
        int num1 = negative.top();
        negative.pop();
        int num2 = negative.top();
        negative.pop();
        sum += (num1 * num2);
    }
    
    while (!positive.empty()) {
        int num1 = positive.top();
        positive.pop();
        int num2 = positive.top();
        positive.pop();
        sum += (num1 * num2);
    }
    
    // 1은 그냥 더한다.
    cout << sum + one << '\n';
    return 0;
}
