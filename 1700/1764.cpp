// BOJ 1764 - 듣보잡
// 첫 번째 풀이
// 듣도 못한 사람을 set container에 담아서 보관한 후,
// 보도 못한 사람들을 입력하면서 해당 사람이 set container에 존재하면
// vector에 담아 문제를 해결했지만
// -> 틀렸다.
// 두 번째 풀이
// 듣도 못한 사람을 입력 받은 뒤, 사전순으로 정렬하고
// 보도 못한 사람을 하나씩 입력하면서 이진 탐색을 이용해서
// 듣도 못한 사람에 자기 이름이 있는지 체크 한다.
// 마지막으로 출력할 때 사전순으로 출력해야 한다.
// 따라서 결과를 다음 vector를 정렬하고 출력해야 한다.
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }
    
    sort(names.begin(), names.end());
    
    vector<string> findNames;
    for (int i = 0; i < m; i++) {
        string findName;
        cin >> findName;
        
        int low = 0, high = (int)names.size()-1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (names[mid] > findName) {
                high = mid - 1;
            } else if (names[mid] < findName) {
                low = mid + 1;
            } else {
                findNames.push_back(findName);
                break;
            }
        }
    }
    
    sort(findNames.begin(), findNames.end());
    
    cout << findNames.size() << '\n';
    for (string name : findNames) {
        cout << name << '\n';
    }
    
    return 0;
}
