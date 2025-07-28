#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, W;
    cin >> N >> W;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    int minn = 0, maxx = 0, sum = 0;
    for(int i = 0; i < N; ++i) {
        sum += A[i];
        minn = min(minn, sum);
        maxx = max(maxx, sum);
    }
    int low = max(0, -minn);
    int high = min(W, W - maxx);
    int ans = max(0, high - low + 1);
    cout << ans << endl;
    return 0;
}