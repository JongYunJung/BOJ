// BOJ 2661 - 좋은 수열
// 백트래킹 문제
#include <iostream>
#include <string>

using namespace std;

string answer;
bool found = false;
int n;

bool check(int depth) {
    int size = depth + 1;
    int half = size / 2;
    
    for (int i = 1; i <= half; i++) {
        string a = answer.substr(size - i * 2, i);
        string b = answer.substr(size - i, i);
        
        if (a == b) return false;
    }
    
    return true;
}

void dfs(int depth) {
    if (found) return;
    
    if (depth == n) {
        cout << answer << '\n';
        found = true;
        return;
    }
    
    for (int i = 1; i <= 3; i++) {
        answer[depth] = i + '0';
        if (check(depth)) dfs(depth + 1);
        answer[depth] = '0';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    answer.resize(n);
    dfs(0);
    
    return 0;
}
