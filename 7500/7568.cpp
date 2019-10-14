// BOJ 7568 - 덩치
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<tuple<int, int, int> > person(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        person[i] = make_tuple(x, y, 1);    // 초기 등수는 1등
    }
    
    vector<int> answer(n);
    for (int i = 0; i < n; i++) {
        int aX, aY, rank;
        tie(aX, aY, rank) = person[i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int bX = get<0>(person[j]);
            int bY = get<1>(person[j]);
            // 몸무게, 키 모두 작으면 등수를 올린다.
            if (aX < bX && aY < bY) {
                rank++;
            }
        }
        answer[i] = rank;
    }
    
    for (int rank : answer) {
        cout << rank << " ";
    }
    cout << '\n';
    
    return 0;
}
