// BOJ 1182
#include <stdio.h>
#include <vector>
using namespace std;

int go(vector<int>& a, int sum, int index, int goal)
{
    if (index == a.size())
    {
        if (sum == goal)
            return 1;
        else
            return 0;
    }
    
    int ans = 0;
    ans += go(a, sum+a[index], index+1, goal);
    ans += go(a, sum, index+1, goal);
    
    return ans;
}

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    
    int ans = go(a, 0, 0, s);
    
    if (s == 0)
        --ans;
    
    printf("%d\n", ans);
    
    return 0;
}

