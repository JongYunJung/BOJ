// BOJ 2503 - 숫자 야구
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<tuple<int, int, int> > info;
    for (int i = 0; i < n; i++) {
        int number, strike, ball;
        cin >> number >> strike >> ball;
        info.push_back(make_tuple(number, strike, ball));
    }
    
    int answer = 0;
    for (int number = 123; number <= 987; number++) {
        string src = to_string(number);
        
        if (src[0] == src[1] || src[0] == src[2] || src[1] == src[2]) {
            continue;
        }
        
        if (src[0] == '0' || src[1] == '0' || src[2] == '0') {
            continue;
        }
        
        // 해당 number가 n개의 숫자의 조건을 만족하는지 체크
        bool ok = true;
        for (int i = 0; i < n; i++) {
            string dst = to_string(get<0>(info[i]));
            
            int strike = 0, ball = 0;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == k && src[j] == dst[k]) {
                        strike++;
                        continue;
                    }
                    if (j != k && src[j] == dst[k]) {
                        ball++;
                        continue;
                    }
                }
            }
            
            
            if (strike != get<1>(info[i]) || ball != get<2>(info[i])) {
                ok = false;
                break;
            }
        }
        
        // n개의 숫자의 조건을 만족한다면, 정답일 가능성이 있다고 판단한다.
        if (ok) answer++;
    }
    
    cout << answer << '\n';
    
    return 0;
}
