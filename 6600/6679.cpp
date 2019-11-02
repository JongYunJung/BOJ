// BOJ 6679 - 싱기한 네자리 숫자
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for (int num = 1000; num <= 9999; num++) {
        int tempNum = num;

        int value1 = 0;
        while (tempNum != 0) {
            value1 += tempNum % 10;
            tempNum /= 10;
        }
        
        tempNum = num;
        
        int value2 = 0;
        while (tempNum != 0) {
            value2 += tempNum % 12;
            tempNum /= 12;
        }
        
        tempNum = num;
        
        int value3 = 0;
        while (tempNum != 0) {
            value3 += tempNum % 16;
            tempNum /= 16;
        }
        
        if (value1 == value2 && value1 == value3 && value2 == value3) {
            cout << num << '\n';
        }
    }
    
    return 0;
}
