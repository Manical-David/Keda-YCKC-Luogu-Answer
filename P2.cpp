#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    long long sum = 0;
    long long s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
        s += nums[i] * nums[i];
    }
    long long res = (sum * sum - s) / 2;
    cout << res << endl;
    return 0;
}