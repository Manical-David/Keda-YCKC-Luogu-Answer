#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> arrs;
    for (int i = 0; i < N; ++i) {
        int SUM;
        cin >> SUM;
        vector<int> arr(SUM);
        for (int j = 0; j < SUM; ++j) {
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end());
        arrs.push_back(arr);
    }
    sort(arrs.begin(), arrs.end());
    for (const auto& arr : arrs) {
        for (size_t i = 0; i < arr.size(); ++i) {
            if (i > 0) {
                cout << " ";
            }
            cout << arr[i];
        }
        cout << '\n';
    }
    return 0;
}