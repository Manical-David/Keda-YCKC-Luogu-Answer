#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    int maxlenth = INT_MIN;
    
    string iisstring;
    while (n--) {
        string str;
        cin >> str;
        iisstring += (str + '\n');
        maxlenth = max(maxlenth, int(str.size()));
    }
    istringstream iis(iisstring);
    int m = maxlenth;
    string s;
    while(getline(iis, s)) {
        int cnt = (m - s.size()) / 2 - 1;
        for (int i = 0; i <= cnt; i++) {
            cout << '.';
        }
        cout << s;
        for (int i = 0; i <= cnt; i++) {
            cout << '.';
        }
        cout << endl;
    }
    return 0;
}