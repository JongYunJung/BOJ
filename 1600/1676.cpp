// BOJ 1676 - 팩토리얼 0의 개수
// 처음에는 단순히 팩토리얼을 계산해서 0의 갯수를 찾는 문제인줄 알았다.
// 문제의 조건을 보니 n = 500 이라서 불가능하다.
// 블로그를 참고 했는데 "0은 10을 얼마나 곱하느냐에 따라 결정 되는 문제" 라고 한다.
// 따라서, 팩토리얼을 이루는 수 중에서 2와 5의 갯수에 따라 0의 개수를 알 수 있다.
// ex)
// 10! = 3628800
// 10! = 1 x 2 x 3 x 4 x 5 x 6 x 7 x 8 x 9 x 10
// 10! = 1 x 2 x 3 x (2 x 2) x 5 x (2 x 3) x 7 x (2 x 2 x 2) x (3 x 3) x (2 x 5)
// 10! = 2^8 x 3^4 x 5^2 x 7
// 10! = (2^2 x 5^2) x 2^6 x 3^4 x 7
// 10! = 10^2 x 2^6 x 3^4 x 7
// 2와 5의 개수 중 작은 값이 10의 개수 (0의 개수)가 된다.
// [참고] : https://ksj14.tistory.com/entry/BackJoon1676-%ED%8C%A9%ED%86%A0%EB%A6%AC%EC%96%BC-0%EC%9D%98-%EA%B0%9C%EC%88%98
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int two = 0;
    int five = 0;
    
    for (int i = 2; i <= n; i *= 2) {
        two += n / i;
    }
    
    for (int i = 5; i <= n; i *= 5) {
        five += n / i;
    }
    
    cout << ((two > five) ? five : two) << '\n';
    
    // 5의 갯수는 2의 갯수보다 무조건 작기 때문에 실은 2의 결과는 생략해도 된다.
    // 이렇게 해도 결과 나옴
    // int five = 0;
    // for (int i = 5; i <= n; i *= 5) {
    //     five += n / i;
    // }
    // cout << five << '\n';
    
    return 0;
}
