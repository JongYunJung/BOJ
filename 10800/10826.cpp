// BOJ 10826 - 피보나치 수 4
// 첫 번째 시도
// map 컨테이너를 사용해서 값을 캐싱하려고 했다. (dp 방법) -> 메모리를 많이 쓴다.
// 두 번째 시도
// map 컨테이너를 사용하지 않고 주어진 string 변수를 재활용한다.
// temp1 = 이전 temp2, temp2 = 이전 temp1 + 이전 temp2
// temp1 = "0", temp2 = "1"
// temp1 = "1", temp2 = "1"
// temp1 = "1", temp2 = "2"
// temp1 = "2", temp2 = "3"
// temp1 = "3", temp2 = "5"
// 다음과 같은 방법으로 메모리를 6배나 줄일 수 있었다.
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    string temp1 = "0", temp2 = "1", curValue;
    for (int i = 2; i <= n; i++) {
        size_t tempSize1 = temp1.size();
        size_t tempSize2 = temp2.size();
        
        // curValue.assign(max(tempSize1, tempSize2), '0');
        // or
        curValue.resize(max(tempSize1, tempSize2));
        size_t curValueSize = curValue.size();
        
        int carry = 0;
        for (int i = 0; i < curValueSize; i++) {
            int sum = carry;
            carry = 0;
            
            if (i < tempSize1) sum += temp1[tempSize1 - i - 1] - '0';
            if (i < tempSize2) sum += temp2[tempSize2 - i - 1] - '0';
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            }
            
            curValue[curValueSize - i - 1] = sum + '0';
        }
        
        if (carry) curValue.insert(curValue.begin(), '1');
        
        temp1 = temp2;
        temp2 = curValue;
    }
    
    if (n == 0) cout << "0" << '\n';
    else if (n == 1) cout << "1" << '\n';
    else cout << curValue << '\n';
    
    return 0;
}
