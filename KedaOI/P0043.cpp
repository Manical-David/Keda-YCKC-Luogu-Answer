#include <bits/stdc++.h>
using namespace std;
bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}
string int_string(int num) {
    return to_string(num);
}
string maxn(vector<int>& nums) {
    vector<string> strs;
    transform(nums.begin(), nums.end(), back_inserter(strs), int_string);
    sort(strs.begin(), strs.end(), cmp);
    string res;
    for (const string& str : strs) {
        res += str;
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << maxn(nums) << endl;
    return 0;
}