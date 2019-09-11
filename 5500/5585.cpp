// BOJ 5585 - 거스름돈
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> coins = {500, 100, 50, 10, 5, 1};
    
    int moneyToPay;
    cin >> moneyToPay;
    
    int change = 1000 - moneyToPay;
    
    int answer = 0;
    for (int i = 0; i < coins.size(); i++) {
        if (change == 0) break;
        while (change >= coins[i]) {
            change -= coins[i];
            answer++;
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}
