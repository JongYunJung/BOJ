// BOJ 2941 - 크로아티아 알파벳
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    cin >> str;
    int i = 0, ans = 0;
    while(i < str.length()) {
        if (i+1 < str.length()) {
            switch (str[i]) {
                case 'c':
                    if (str[i+1] == '=' || str[i+1] == '-') i += 1;
                    break;
                case 'd':
                    if (str[i+1] == 'z' && i+2 < str.length() && str[i+2] == '=') i += 2;
                    else if (str[i+1] == '-') i += 1;
                    break;
                case 'l': case 'n':
                    if (str[i+1] == 'j') i += 1;
                    break;
                case 's': case 'z':
                    if (str[i+1] == '=') i += 1;
                    break;
            }
        }
        i++;
        ans++;
    }
    
    cout << ans << '\n';
    return 0;
}

