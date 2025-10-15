#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("string.in", "r", stdin);
    // freopen("string.out", "w", stdout);
    int n;
    string s;
    cin >> n >> s;
    int i = 0;
    while (i <= n - 3) {
        if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
            s[i] = 'c';
            s[i+1] = 'b';
            s[i+2] = 'a';
            i = max(0, i - 2);
        } else {
            i++;
        }
    }
    cout << s << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
