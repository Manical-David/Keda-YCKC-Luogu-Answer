#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int t;
    cin >> t;
    int hours = t / 3600;
    t -= (hours * 3600);
    int minutes = t / 60;
    t -= (60 * minutes);
    int second = t;
    cout << hours << " hours\n";
    cout << minutes << " minutes\n";
    cout << second << " seconds\n";
    return 0;
}