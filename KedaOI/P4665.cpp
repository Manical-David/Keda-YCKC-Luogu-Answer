#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n;
    cin >> n;
    vector <int> nums(n);
    for (int i = 0; i < n; i++) {
        int tong;
        cin >> tong;
        if(tong > 0) {
            nums.push_back(tong);
        }
    }
    sort(nums.begin(), nums.end());
    return 0;
}