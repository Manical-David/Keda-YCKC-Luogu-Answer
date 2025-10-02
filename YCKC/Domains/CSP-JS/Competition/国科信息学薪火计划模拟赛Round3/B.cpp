#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("gaming.in", "r", stdin);
    freopen("gaming.out", "w", stdout);
    int n;
    cin >> n;
    int dcd, datk, dhp;
    cin >> dcd >> datk >> dhp;
    vector<string> res;
    for (int i = 0; i < n; ++i) {
        int typ, cd, atk, hp;
        cin >> typ >> cd >> atk >> hp;
        if (typ == 0) {
            int datt = (hp + datk - 1) / datk;
            int sum = (datt - 1) * atk;
            res.push_back(sum >= dhp ? "1" : "0");
        } else {
            int waratt = (dhp + atk - 1) / atk;
            int wart = (waratt - 1) * cd;
            int datt = (hp + datk - 1) / datk;
            int dt = (datt - 1) * dcd;
            res.push_back(wart <= dt ? "1" : "0");
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}