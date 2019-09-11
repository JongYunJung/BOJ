// BOJ 2960 - 에라토스테네스의 체
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<bool> check(n+1);
    vector<int> answers;
    for (int i = 2; i <= n; i++) {
        if (!check[i]) {
            answers.push_back(i);
            check[i] = true;
        }
        for (int j = i * i; j <= n; j += i) {
            if (check[j]) continue;
            answers.push_back(j);
            check[j] = true;
        }
    }
    
    cout << answers[k-1] << '\n';
    return 0;
}
