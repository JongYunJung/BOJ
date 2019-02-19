// BOJ 1149
#include <stdio.h>

int min(int a, int b) {
    return (a>b)?b:a;
}

int main() {
    int dp[1001][3]={0,};
    int n,r,g,b;
    
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d %d %d",&r,&g,&b);
        dp[i][0] = min(dp[i-1][1]+r, dp[i-1][2]+r);
        dp[i][1] = min(dp[i-1][0]+g, dp[i-1][2]+g);
        dp[i][2] = min(dp[i-1][0]+b, dp[i-1][1]+b);
    }
    printf("%d\n",min(min(dp[n][0], dp[n][1]),dp[n][2]));
    return 0;
}

