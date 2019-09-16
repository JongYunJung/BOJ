// BOJ 2822 - 점수 계산
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<pair<int, int> > score(8);
    for (int i = 0; i < 8; i++) {
        cin >> score[i].first;
        score[i].second = i + 1;
    }
    
    sort(score.begin(), score.end(), compare);
    
    vector<int> numbers;
    int totalScore = 0;
    for (int i = 0; i < 5; i++) {
        totalScore += score[i].first;
        numbers.push_back(score[i].second);
    }
    
    cout << totalScore << '\n';
    
    sort(numbers.begin(), numbers.end());
    
    for (int number : numbers) {
        cout << number << " ";
    }
    
    cout << '\n';
    
    return 0;
}
