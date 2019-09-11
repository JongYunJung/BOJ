// BOJ 2798 - 블랙잭
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum <= m && answer < sum) {
                    answer = sum;
                }
            }
        }
    }
    
    cout << answer << '\n';
    return 0;
}
