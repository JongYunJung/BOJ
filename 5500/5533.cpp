// BOJ 5533 - 유니크
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<int> > score(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> score[i][0] >> score[i][1] >> score[i][2];
    }
    
    vector<int> answer(n);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            bool flag = true;
            for (int k = 0; k < n; k++) {
                if (j == k) continue;
                if (score[j][i] == score[k][i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                answer[j] += 0;
            } else {
                answer[j] += score[j][i];
            }
        }
    }
    
    for (int totalScore : answer) {
        cout << totalScore << '\n';
    }
    
    return 0;
}
