// BOJ 5543 - 상근날드
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> arrs(5);
    for (int i = 0; i < 5; i++) {
        cin >> arrs[i];
    }
    
    int burger = 2000;
    for (int i = 0; i < 3; i++) {
        burger = min(burger, arrs[i]);
    }
    
    int drink = 2000;
    for (int i = 3; i < 5; i++) {
        drink = min(drink, arrs[i]);
    }
    
    cout << burger + drink - 50 << '\n';
    
    return 0;
}
