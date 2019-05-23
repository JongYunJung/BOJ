// BOJ 10214 - Baseball
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> yonseiScore(9);
    vector<int> koreaScore(9);
    
    int tc;
    cin >> tc;
    while (tc--) {
        yonseiScore.clear();
        koreaScore.clear();
        for (int i = 0; i < 9; i++) {
            cin >> yonseiScore[i] >> koreaScore[i];
        }
        
        int yonseiTotalScore = 0;
        int koreaTotalScore = 0;
        for (int i = 0; i < 9; i++) {
            yonseiTotalScore += yonseiScore[i];
            koreaTotalScore += koreaScore[i];
        }
        
        if (yonseiTotalScore > koreaTotalScore) cout << "Yonsei";
        else if (yonseiTotalScore < koreaTotalScore) cout << "Korea";
        else cout << "Draw";
        cout << '\n';
    }
    
    return 0;
}
