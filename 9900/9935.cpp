// BOJ 9935 - 문자열 폭발
// 폭발 문자열의 끝과 현재 문자열이 일치하면 제거할지 판단해야한다.
// 제거할때는 idx라는 인덱스를 활용한다. (일치하면.. idx -= 폭발 문자열의 길이로 초기화 한다.)
// idx를 초기화 하면 그 위치부터 다시 문자열을 넣으면 된다.
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str, explosion;
    cin >> str >> explosion;
    
    vector<char> answer(MAX+1);
    int idx = 0;
    for (int i = 0; i < str.length(); i++) {
        answer[idx++] = str[i];
        if (answer[idx-1] == explosion[explosion.length()-1]) {
            if (idx - explosion.length() < 0) continue;
            bool detected = true;
            for (int j = 0; j < explosion.length(); j++) {
                if (answer[idx-j-1] != explosion[explosion.length()-j-1]) {
                    detected = false;
                    break;
                }
            }
            if (detected) idx -= explosion.length();
        }
    }
    
    if (idx == 0) cout << "FRULA" << '\n';
    else {
        for (int i = 0; i < idx; i++) cout << answer[i];
        cout << '\n';
    }
    return 0;
}

