// BOJ 10757 - 큰 수 A+B
// 입력으로 들어오는 수가 굉장히 크다.. 정수 타입으로 표현할 수 없음
// 그래서 string형으로 처리를 해야 하고, 자리 올림 수 체크하는 것이 중요하다.
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;
    
    size_t aSize = a.size();
    size_t bSize = b.size();
    
    string answer(max(aSize, bSize), '0');
    
    size_t answerSize = answer.size();
    
    int carry = 0;
    for (int i = 0; i < answerSize; i++) {
        int sum = carry;
        carry = 0;
        
        if (i < aSize) sum += a[aSize - i - 1] - '0';
        if (i < bSize) sum += b[bSize - i - 1] - '0';
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        }
        
        answer[answerSize - i - 1] = sum + '0';
    }
    
    if (carry) answer.insert(answer.begin(), '1');
    
    cout << answer << '\n';
    
    return 0;
}
