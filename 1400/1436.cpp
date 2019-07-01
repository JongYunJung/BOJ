// BOJ 1436 - 영화감독 숌
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int num = 666, turn = 1;
    while (true) {
        if (turn == n) break;
        
        string answer = "";
        int tempNum = ++num;
        while (tempNum) {
            answer += (tempNum % 10 + '0');
            tempNum /= 10;
        }
        tempNum = stoi(answer);
        
        int six = 0;
        while (tempNum) {
            if (tempNum % 10 == 6) six++;
            else if (six < 3) six = 0;
            tempNum /= 10;
        }
        
        if (six >= 3) turn++;
    }
    
    cout << num << '\n';
    return 0;
}
