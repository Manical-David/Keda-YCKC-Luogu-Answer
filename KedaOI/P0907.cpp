#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e4 + 7;
int n, m;
int houses[N], heater[N];
bool best(int i, int j) {
    return (j == m - 1) ||
           ((abs(heater[j] - houses[i])) 
           < abs(heater[j + 1] - houses[i]));
}    
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> houses[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> heater[i];
    }
    sort(houses, houses + n);
    sort(heater, heater + m);
    int res = 0;
    // 
    for(int i = 0, j = 0; i < n; i++) {
        while(!best(i, j)) j ++;
        res = max(res, abs(heater[j] - houses[i]));
    }
    cout << res << '\n';
    return 0;
}