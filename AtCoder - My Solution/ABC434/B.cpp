#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <double> > birds(m, vector <double> ());
    vector <double> cnt(m, 0);
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        birds[x - 1].push_back(y);
        cnt[x - 1] += y;
    }
    vector <double> count(m);
    for (int i = 0; i < m; i++) {
        count[i] = birds[i].size();
    }
    for (int i = 0; i < m; i++) {
        cout << cnt[i] / count[i] << '\n';
    }
    return 0;
}