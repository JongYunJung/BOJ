// BOJ 3111 - 검열
// 해결하지 못해서 블로그를 보며 이해하고 구현했다.
// 참고 사이트 : https://jaimemin.tistory.com/1126
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string word, text;
    cin >> word >> text;
    
    deque<char> left, right;
    int front = 0, end = (int)text.length()-1;
    while (front <= end) {
        // 2번 조건
        while (front <= end) {
            bool ok = false;
            left.push_back(text[front++]);
            if (left.size() >= word.length()) {
                ok = true;
                for (int i = 0; i < word.length(); i++) {
                    if (word[i] != left[left.size()-word.length()+i]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                size_t popCount = word.length();
                while(popCount--) left.pop_back();
                break;
            }
        }
        // 4번 조건
        while (front <= end) {
            bool ok = false;
            right.push_front(text[end--]);
            if (right.size() >= word.length()) {
                ok = true;
                for (int i = 0; i < word.length(); i++) {
                    if (word[i] != right[i]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                size_t popCount = word.length();
                while(popCount--) right.pop_front();
                break;
            }
        }
    }
    
    string answer = "";
    for (int i = 0; i < left.size(); i++) answer += left[i];
    for (int i = 0; i < right.size(); i++) answer += right[i];
    
    // 핵심!!!!!! 두 deque를 합쳤을 때 나올 수 있는 word 지우기
    // 왜 30000으로 하는거지..? 분석해봐야하는데..
    while (answer.find(word) < 30000) answer.erase(answer.find(word), word.length());
    cout << answer << '\n';
    
    return 0;
}

