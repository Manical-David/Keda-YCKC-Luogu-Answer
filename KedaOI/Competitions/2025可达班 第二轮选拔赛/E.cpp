#include <bits/stdc++.h>
using namespace std;
struct paint {
    double begin, end;
    int value;
};
bool cmp(const paint &a, const paint &b) {
    return a.end < b.end;
}
int main() {
    int N, L;
    cin >> N >> L;
    vector<paint> paints;
    for (int i = 0; i < N; ++i) {
        int w, v;
        cin >> w >> v;
        if (w <= L) {
            double begin = w / 2.0;
            double end = L - w / 2.0;
            paints.push_back({begin, end, v});
        }
    }
    sort(paints.begin(), paints.end(), cmp);
    // 贪心
    int Max = 0;
    double last_end = -1;
    for (auto &p : paints) {
        if (p.begin >= last_end) {
            Max += p.value;
            last_end = p.end;
        }
    }
    cout << Max << endl;
    return 0;
}
