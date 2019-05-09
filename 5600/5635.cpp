// BOJ 5635 - 생일
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<tuple<string, int, int, int> > info;
    for (int i = 0; i < n; i++) {
        string name;
        int d, m, y;
        cin >> name >> d >> m >> y;
        info.push_back(make_tuple(name, d, m, y));
    }
    
    sort(info.begin(), info.end(),
         [](const tuple<string, int, int, int>& a,
            const tuple<string, int, int, int>& b) {
             int aD, aM, aY, bD, bM, bY;
             tie(ignore, aD, aM, aY) = a;
             tie(ignore, bD, bM, bY) = b;
             
             if(aY == bY && aM == bM) return aD > bD;
             else if (aY == bY) return aM > bM;
             else return aY > bY;
         });
    
    cout << get<0>(info.front()) << '\n';
    cout << get<0>(info.back()) << '\n';
    return 0;
}

