#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    long long T;
    cin >> N >> T;
    vector<pair<long long, long long>> dell;
    for (int i = 0; i < N; ++i) {
        long long d, b;
        cin >> d >> b;
        dell.emplace_back(d, b);
    }
    long long hay = 0;
    long long lastday = 0;
    long long sum = 0;
    for (const auto& ts : dell) {
        long long d = ts.first;
        long long b = ts.second;
        long long daysa = d - lastday - 1;
        if (daysa > 0) {
            long long eat = min(daysa, hay);
            sum += eat;
            hay -= eat;
        }
        hay += b;
        lastday = d - 1;
        if (hay == 0) continue;
        long long next_d = (ts == dell.back()) ? T + 1 : dell[&ts - &dell[0] + 1].first;
        long long end_day = min(next_d - 1, T);
        long long dap = end_day - d + 1;
        long long eat = min(dap, hay);
        sum += eat;
        hay -= eat;
        lastday = d + eat - 1;
        if (lastday >= T) break;
    }
    cout << sum << endl;   
    return 0;
}