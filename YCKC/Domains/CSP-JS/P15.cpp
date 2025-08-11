#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    unordered_map<int, int> las;
    int maxx = 0;
    int i = 0;
    for (int j = 0; j < n; ++j) {
        if (las.find(nums[j]) != las.end() && las[nums[j]] >= i) {
            i = las[nums[j]] + 1;
        }
        las[nums[j]] = j;
        maxx = max(maxx, j - i + 1);
    }
    cout << maxx << endl;
    return 0;
}