#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1005;
int zhongjiang[7];
bool win[34]; // 1~33

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> b(7);
    for(int i = 0; i < 7; i++) {
        cin >> b[i];
        win[b[i]] = true;
    }
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < 7; j++) {
            int x;
            cin >> x;
            if(win[x]) cnt++;
        }
        if(cnt >= 1 && cnt <= 7)
            zhongjiang[7 - cnt]++;
    }
    for(int i = 0; i < 7; i++) {
        cout << zhongjiang[i] << ' ';
    }
    return 0;
}