// BOJ 1517 - 버블 소트
// mid를 기준으로 왼쪽에 남아있는 원소의 수 만큼 swap 한다.
// swapCount += (m + 1 - i)
#include <iostream>
#include <vector>
using namespace std;
long long swapCount = 0;
const int MAX = 500001;
int sorted[MAX];

void merge(vector<int>& arr, int s, int m, int e) {
    int idx = s;
    int i = s, j = m+1;
    while (i <= m && j <= e) {
        if (arr[i] <= arr[j])
            sorted[idx++] = arr[i++];
        else {
            sorted[idx++] = arr[j++];
            swapCount += (m + 1 - i);
        }
    }
    
    while (i <= m) sorted[idx++] = arr[i++];
    while (j <= e) sorted[idx++] = arr[j++];
    for (int k = s; k <= e; k++) arr[k] = sorted[k];
}

void mergeSort(vector<int>& arr, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(arr, s, m);
        mergeSort(arr, m+1, e);
        merge(arr, s, m, e);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    mergeSort(arr, 0, n-1);
    cout << swapCount << '\n';
    
    return 0;
}
