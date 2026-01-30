#include <bits/stdc++.h> 
using namespace std;
struct fw {
    int n;
    vector<int> bit;
    fw(int n = 0) : n(n), bit(n + 1, 0) {}
    void add(int idx, int val = 1) {
        for (; idx <= n; idx += idx & -idx) // A special FOR-LOOP
            bit[idx] += val;
    }
    int sum(int idx) {
        int r = 0;
        for (; idx > 0; idx -= idx & -idx) 
            r += bit[idx];
        return r;
    }
};
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> b(n + 1), pos_of(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> b[i];
        pos_of[b[i]] = i;
    }
    fw fw(n);
    long long ans = 0;
    int ins = 0;
    for (int b = 1; b <= n; ++b){
        int pos = pos_of[b];
        ++ins;
        long long lc = fw.sum(pos);
        long long t = lc + 1;
        ans += t * (ins - t + 1);
        fw.add(pos, 1);
    }
    cout << ans << '\n';
    return 0;
}