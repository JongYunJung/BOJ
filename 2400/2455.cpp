// BOJ 2455 - 지능형 기차
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int person = 0;
    int max_person = 0;
    for (int i = 0; i < 4; i++) {
        int out, in;
        cin >> out >> in;
        person = person - out + in;
        max_person = max(max_person, person);
    }
    cout << max_person << '\n';
    
    return 0;
}
