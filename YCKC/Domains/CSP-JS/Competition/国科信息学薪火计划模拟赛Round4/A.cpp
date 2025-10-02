#include <bits/stdc++.h>
using namespace std;
int char_int(char c) {
    return int(c - '0');
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    string str;
    getline(cin, str);
    sort(str.begin(), str.end());
    int sum = 0;
    bool flag = false;
    for(int i = str.size() - 1; i >= 0; i--) {
        flag = (char_int(str[i]) == 0 ? false : true);
        if(flag) {
            sum += char_int(str[i]);
        }
        else if(!flag) break;
    }
    if(sum % 3 == 0) {
        reverse(str.begin(), str.end());
        cout << str << '\n';
    }
    else cout << -1 << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}