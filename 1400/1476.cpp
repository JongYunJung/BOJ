// BOJ 1476 - 날짜 계산
#include <stdio.h>
using namespace std;

int main()
{
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);
    
    E -= 1, S -= 1, M -= 1;
    
    int year = 0;
    while (true)
    {
        if (year % 15 == E && year % 28 == S && year % 19 == M)
        {
            printf("%d\n", year+1);
            break;
        }
        
        ++year;
    }
    
    return 0;
}
