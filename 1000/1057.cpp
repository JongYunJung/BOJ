// BOJ 1057 - 토너먼트
// 문제 해결 방법이 생각나지 않아서 참고했다.
// 수학 문제
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int people, jimin, hansu;
    cin >> people >> jimin >> hansu;
    
    // 만나지 않을때 -1 출력
    // 토너먼트이고, 지민이랑 한수는 무조건 이기기 때문에 언젠가 특정 라운드에서 만나게 된다.
    // 따라서 만나지 않는다는 것은 특별한 예외이다.
    // 그말인 즉슨, 지민이랑 한수의 번호가 전체 사람의 수 보다 크면 -1 을 출력하면 된다는 것.
    int round = -1;
    if (jimin <= people && hansu <= people) {
        // 다음 라운드를 진출할때마다 번호가 갱신되기 때문에
        // (현재 번호 + 1) / 2 의 결과는 다음 라운드의 번호이다.
        // 따라서 지민이랑 한수 둘 다 번호가 같아진다는 의미는 해당 라운드에서 만난다는 의미이다.
        round = 0;
        while (jimin != hansu) {
            jimin = (jimin + 1) / 2;
            hansu = (hansu + 1) / 2;
            ++round;
        }
    }
    
    cout << round << '\n';
    return 0;
}

