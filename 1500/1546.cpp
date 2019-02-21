// BOJ 1546 - 평균
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int max = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (max < a[i]) {
            max = a[i];
        }
    }
    
    double sum = 0.f;
    for (int i = 0; i < n; i++) {
        sum += (double)a[i] / (double)max * 100.f;
    }
    printf("%0.2f\n", sum/(double)n);
    
    return 0;
}
