// BOJ 5597 - 과제 안 내신 분..?
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<bool> check(31);
    for (int i = 0; i < 28; i++) {
        int number;
        cin >> number;
        check[number] = true;
    }
    
    for (int num = 1; num <= 30; num++) {
        if (check[num]) continue;
        cout << num << '\n';
    }
    
    return 0;
}
