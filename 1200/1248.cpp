// BOJ 1248
#include <iostream>
using namespace std;

int sign[10][10];
int ans[10];
int n;

bool check(int index) {
    int sum = 0;
    for (int i = index; i >= 0; i--) {
        sum += ans[i];
        if (sign[i][index] < 0 && sum >= 0) {
            return false;
        }
        if (sign[i][index] > 0 && sum <= 0) {
            return false;
        }
        if (sign[i][index] == 0 && sum != 0) {
            return false;
        }
    }
    return true;
}

bool go(int index) {
    if (index == n)
        return true;
    if (sign[index][index] == 0) {
        ans[index] = 0;
        return (check(index) && go(index+1));
    }
    for (int i = 1; i <= 10; i++) {
        ans[index] = i * sign[index][index];
        if (check(index) && go(index+1))
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            char ch;
            cin >> ch;
            if (ch == '-') {
                sign[i][j] = -1;
            } else if (ch == '+') {
                sign[i][j] = 1;
            } else {
                sign[i][j] = 0;
            }
        }
    }
    
    go(0);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
