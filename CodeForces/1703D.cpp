#include <bits/stdc++.h>
using namespace std;
string str[100010];
bool f[100010];
map<string, int> s;
int t, n;
int main() {
    cin >> t;
    while (t--) {
        s.clear();
        memset(f, 0, sizeof(f));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> str[i];
            s[str[i]] = 1;
        }
        for (int k = 1; k <= n; k++)
            for (int i = 0; i < str[k].size(); i++) {
                string q = str[k].substr(0, i), h = str[k].substr(i, str[k].size());
                if (s[q] == 1 && s[h] == 1)
                    f[k] = 1;
            }
        for (int i = 1; i <= n; i++)
            cout << f[i];
        cout << endl;
    }
    return 0;
}