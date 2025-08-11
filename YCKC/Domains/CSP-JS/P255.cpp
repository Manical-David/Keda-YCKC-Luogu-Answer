// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//     string str;
//     cin >> str;
//     do {
//         cout << str << '\n';
//     } while(next_permutation(str.begin(), str.end()));
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<string> res;
map<int, char> mp;
bool vis[25];
int n;
void dfs(string x, vector<bool>& vis) {
    if (x.size() == n) {
        res.push_back(x);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            x += mp[i];
            dfs(x, vis);
            x.pop_back();
            vis[i] = false;
        }
    }
}

int main() {
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; ++i) {
        mp[i] = s[i];
    }
    vector<bool> vis(n, false);
    dfs("", vis);
    for (const auto str : res) {
        cout << str << endl;
    }
    
    return 0;
}