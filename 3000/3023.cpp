// BOJ 3023 - 마술사 이민혁
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int r, c;
    cin >> r >> c;
    
    vector<vector<char> > base(r, vector<char>(c));
    vector<vector<char> > card(2 * r, vector<char>(2 * c));
    
    int cardRSize = (int)card.size();
    int cardCSize = (int)card[0].size();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> base[i][j];
            card[i][j] = base[i][j];
            card[i][cardCSize - 1 - j] = base[i][j];
        }
        for (int j = 0; j < cardCSize; j++) {
            card[cardRSize - 1 - i][j] = card[i][j];
        }
    }
    
    int a, b;
    cin >> a >> b;
    card[a-1][b-1] = (card[a-1][b-1] == '#') ? '.' : '#';
    
    for (int i = 0; i < cardRSize; i++) {
        for (int j = 0; j < cardCSize; j++) {
            cout << card[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}
