// BOJ 1208 - 1
#include <stdio.h>
#include <vector>
using namespace std;
// 아이디어가 생각이 나지 않아.. 참고하였음..
// 부분 집합은 N = 20, 부분 집합 2는 N = 40인 점을 생각하여 풀 것
enum { EMaxSize = 2000001 };    // 40 / 2 + 100,001 (정수 최대의 절대 값)
vector<int> plus_sum_table, minus_sum_table;
vector<int> input_arr;
long long caseCount = 0;
int N, S;

void DFS(int begin, int end, int sum, bool firstFlag)
{
    if (begin == end)
    {
        if (firstFlag)
        {
            if (sum >= 0)
                plus_sum_table[sum]++;
            else
                minus_sum_table[-sum]++;
        }
        else
        {
            int target = S - sum;
            
            if (target > -EMaxSize && target < EMaxSize)
            {
                if (target >= 0)
                    caseCount += plus_sum_table[target];
                else
                    caseCount += minus_sum_table[-target];
            }
        }
        return;
    }
    
    // 자기를 포함하지 않은 부분 집합
    DFS(begin+1, end, sum, firstFlag);
    // 자기를 포함한 부분 집합
    DFS(begin+1, end, sum+input_arr[begin], firstFlag);
}

int main()
{
    scanf("%d %d", &N, &S);
    
    plus_sum_table = vector<int>(EMaxSize);
    minus_sum_table = vector<int>(EMaxSize);
    input_arr = vector<int>(N);
    
    for (int i = 0; i < N; ++i)
        scanf("%d", &input_arr[i]);
    
    DFS(0, N/2, 0, true);
    DFS(N/2, N, 0, false);
    
    // 합이 0이 되어야 하는 경우에는
    // 왼쪽, 오른쪽 배열에 0(공집합이) 있는 경우가 존재함
    if (S == 0)
        --caseCount;
    
    printf("%lld\n", caseCount);
    
    return 0;
}

