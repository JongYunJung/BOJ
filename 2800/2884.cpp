// BOJ 2884 - 알람 시계
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int hour, minute;
    cin >> hour >> minute;
    
    int alarm_minute = minute - 45;
    if (alarm_minute >= 0) cout << hour << " " << alarm_minute;
    else {
        alarm_minute += 60;
        if (hour - 1 == -1) cout << 23 << " " << alarm_minute;
        else cout << hour - 1 << " " << alarm_minute;
    }
    
    cout << '\n';
    return 0;
}
