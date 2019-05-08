// BOJ 1094 - 막대기
// 수학 & 시뮬레이션 문제
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int x;
    cin >> x;
    
    int length = 64;
    vector<int> sticks;
    sticks.push_back(length);
    while (true) {
        int sum = 0;
        for (int i = 0; i < sticks.size(); i++) {
            sum += sticks[i];
        }
        
        if (sum > x) {
            sort(sticks.begin(), sticks.end(), greater<int>());
            int minStick = sticks.back();
            sticks.pop_back();
            
            minStick /= 2;
            int sum2 = minStick;
            for (int i = 0; i < sticks.size(); i++) {
                sum2 += sticks[i];
            }
            
            if (sum2 >= x) {
                sticks.push_back(minStick);
            } else {
                sticks.push_back(minStick);
                sticks.push_back(minStick);
            }
        } else if (sum == x) {
            cout << sticks.size() << '\n';
            break;
        }
    }
    
    return 0;
}
