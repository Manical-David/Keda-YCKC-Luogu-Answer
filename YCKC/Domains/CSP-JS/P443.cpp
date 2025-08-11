#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    while (M--) {
        int X, Y;
        cin >> X >> Y;
        reverse(arr.begin() + X - 1, arr.begin() + Y);
    }
    for (int i = 0; i < N; ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << arr[i];
    }
    cout << '\n';
    return 0;
}