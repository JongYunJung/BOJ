// BOJ 1019 - 책 페이지 (어렵다..)
// 백준 온라인 강의 수강..
#include <iostream>
using namespace std;
long long ans[10];

void calc(long long n, long long ten) {
    while (n > 0) {
        ans[n%10] += ten;
        n /= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long ten = 1;
    long long start = 1;
    long long end;
    cin >> end;
    
    while (start <= end) {
        // 일의 자리 갯수를 count 해주면서 start의 일의 자리를 0으로 만든다.
        // ex) start = 1345 -> ans의 5,6,7,8,9 에서 calc 함수를 통해 +1 증감 후, 1350으로 만들기
        // ex) start = 135 -> ans의 5,6,7,8,9 에서 calc 함수를 통해 +1 증감 후, 140으로 만들기
        // ex) start = 14 -> ans의 4,5,6,7,8,9 에서 calc 함수를 통해 +1 증감 후, 10으로 만들기
        // ex) start = 1 -> ans의 1,2,3,4,5,6,7,8,9 에서 calc 함수를 통해 +1 증감 후, 10으로 만들기
        while (start % 10 != 0 && start <= end) {
            calc(start, ten);
            ++start;
        }
        
        // 맨 마지막에 break
        // ex) start = 1350, end = 8742 이니깐 pass
        // ex) start = 140, end = 873 이니깐 pass
        // ex) start = 10, end = 86 이니깐 pass
        // ex) start = 10이 되고, end = 7 이므로 break;
        if (start > end)
            break;
        
        // 일의 자리 갯수를 count 해주면서 end의 일의 자리를 9로 만든다.
        // ex) end = 8742 -> ans의 2, 1, 0 에서 calc 함수를 통해 +1 증감 후, 8739로 만들기
        // ex) end = 873 -> ans의 3, 2, 1, 0 에서 calc 함수를 통해 +1 증감 후, 869로 만들기
        // ex) end = 86 -> ans의 6, 5, 4, 3, 2, 1, 0 에서 calc 함수를 통해 +1 증감 후, 79로 만들기
        while (end % 10 != 9 && start <= end) {
            calc(end, ten);
            --end;
        }
        
        // ex) <1350 ~ 8739> => 1350 ~ 1359, 1360 ~ 1369, ... ,8730 ~ 8739 (873-135+1=739개)
        // ex) <140 ~ 869> => 140 ~ 149, 150 ~ 159, ... ,860 ~ 869 (86-14+1=73개)
        // ex) <10 ~ 79> => 10 ~ 19, 20 ~ 29, ... , 70 ~ 79 (7-1+1=7개)
        long long cnt = (end/10 - start/10 + 1);
        
        // 각 숫자가 cnt 만큼 있다.
        // ex) <1350 ~ 8739> => ans[0] = 739 * 1, ans[1] = 739 * 1, ... ,ans[9] = 739 * 1
        //      ten = 1 을 곱하는 이유? 일의 자리 0 ~ 9 밖에 없기 때문
        //      0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        // ex) <140 ~ 869> => ans[0] = 73 * 10, ans[1] = 73 * 10, ... ,ans[9] = 73 * 10
        //      ten = 10 을 곱하는 이유? 십의자리 0 ~ 9, 일의 자리 0 ~ 9 까지 있음..
        //      00,01,02,03,..,10,11,12,...30,31,32,...71,72,74,...97,98,99
        // ex) <10 ~ 79> => ans[0] = 7 * 100, ans[1] = 7 * 100, ... ,ans[9] = 7 * 100
        //      ten = 100 을 곱하는 이유? 십의자리 0 ~ 9, 일의 자리 0 ~ 9, 백의 자리 0 ~ 9 까지 있음
        //      000,001,002,...,111,112,113...,561,562,563...,997,998,999
        for (int i = 0; i <= 9; i++) {
            ans[i] += cnt * ten;
        }
        
        // 자리수를 올려서 다시 구하기
        // ex) 1350 -> 135, 8739 -> 873, ten은 1에서 10으로
        // ex) 140 -> 14, 869 -> 86 ten은 10에서 100으로
        // ex) 10 -> 1, 79 -> 7 ten은 100에서 1000으로
        start /= 10;
        end /= 10;
        ten *= 10;
    }
    
    // 출력
    for (int i = 0; i <= 9; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}

