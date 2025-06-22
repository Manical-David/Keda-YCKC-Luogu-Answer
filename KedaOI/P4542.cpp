#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int cows[N];
int fnd(int x) {
    if (cows[x] != x)
        cows[x] = fnd(cows[x]);
    return cows[x];
}
void unite(int x, int y) {
    int fx = fnd(x);
    int fy = fnd(y);
    if (fx != fy)
        cows[fx] = fy;
}
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; ++i)
        cows[i] = i;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }
    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        if (fnd(x) == fnd(y))
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}