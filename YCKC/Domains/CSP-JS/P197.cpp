#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    const int MAX_SIZE = 1000002;
    vector<int> water(MAX_SIZE, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        water[a] += 1;
        if (b + 1 < MAX_SIZE) {
            water[b + 1] -= 1;
        }
    }
    int maxx = 0;
    int cur = 0;
    for (int i = 0; i < MAX_SIZE; ++i) {
        cur += water[i];
        maxx = max(maxx, cur);
    }
    cout << maxx << endl;
    return 0;
}