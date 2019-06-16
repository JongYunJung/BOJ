// BOJ 1406 - 에디터
// 커서 기준으로 왼쪽으로 올 수 있는 문자들을 head stack에 담고,
// 커서 기준으로 오른쪽으로 올 수 있는 문자들을 tail stack에 담는 자료구조 형태를 만들고
// 4가지 조건을 성립하도록 구현하면 된다.
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    cin >> str;
    
    stack<char> head, tail;
    for (int i = 0; i < str.length(); i++) {
        head.push(str[i]);
    }
    
    int n;
    cin >> n;
    while (n--) {
        char command;
        cin >> command;
        
        if (command == 'L') {
            if (!head.empty()) {
                tail.push(head.top());
                head.pop();
            }
        } else if (command == 'D') {
            if (!tail.empty()) {
                head.push(tail.top());
                tail.pop();
            }
        } else if (command == 'B') {
            if (!head.empty()) head.pop();
        } else if (command == 'P') {
            char ch;
            cin >> ch;
            head.push(ch);
        }
    }
    
    while (!head.empty()) {
        tail.push(head.top());
        head.pop();
    }
    
    string answer = "";
    while (!tail.empty()) {
        answer += tail.top();
        tail.pop();
    }
    
    cout << answer << '\n';
    return 0;
}
