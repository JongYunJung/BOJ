// BOJ 1946 - 신입 사원
// < 조건 >
// 다른 모든 지원자와 비교했을 때 '서류심사 성적' 과 '면접시험 성적' 중
// 적어도 하나가 다른 지원자보다 떨어지지 않는자만 선발한다는 원칙
// < 해결 >
// 1. 서류심사 성적 기준으로 오름 차순 정렬을 한다.
// 2. 서류심사 성적이 1등인 사람을 우선 채용한다.
// why? 문제의 조건을 잘 읽어보고 생각해본다면, 적어도 서류심사 성적만(적어도 하나)큼은 다른 지원자보다 떨어지지 않기 때문에 채용
// 3. 서류심사 성적이 1등인 사람의 면접시험 성적을 기록한다.
// 4. 두 번째 지원자부터 기록된 면접시험 성적보다 우수한 사람을 찾는다.
// 5. 찾았으면 채용하고, 현재 채용한 사람의 면접시험 성적을 다시 기록한다.
// 6. 4 ~ 5번 과정을 반복한다.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        
        vector<pair<int, int> > employee(n);
        for (int i = 0; i < n; i++) {
            cin >> employee[i].first >> employee[i].second;
        }
        
        sort(employee.begin(), employee.end());
        int interviewRank = employee.front().second;
        
        int answer = 1;
        for (int i = 1; i < n; i++) {
            if (employee[i].second < interviewRank) {
                interviewRank = employee[i].second;
                answer++;
            }
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}
