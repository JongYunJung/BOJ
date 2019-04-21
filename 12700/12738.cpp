// BOJ 12015 - 가장 긴 증가하는 부분 수열 2
// BOJ 12738 - 가장 긴 증가하는 부분 수열 3
// LIS 알고리즘을 이분 탐색 기법을 활용해서 풀이 O(NlogN)
// 데이터가 크지 않으면 다이나믹 프로그래밍 기법으로 해도 된다. O(N^2)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> lis(n, 0);
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        int target;
        cin >> target;
        
        if (i == 0) lis[i] = target;
        else {
            if (lis[j] < target) {
                lis[++j] = target;
            } else {
                int left = 0, right = j;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (lis[mid] < target) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                lis[right] = target;
            }
        }
    }
    
    cout << j + 1 << '\n';
    return 0;
}

