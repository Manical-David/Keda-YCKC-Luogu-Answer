#include <bits/stdc++.h>
using namespace std;
int lower(vector<int>& arr, int t) {
    int l = 0, r = arr.size() - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] >= t) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if(l < arr.size() && arr[l] == t) return l;
    return -1;
}
int upper(vector<int>& arr, int t) {
    int l = 0, r = arr.size() - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] <= t) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if(r >= 0 && arr[r] == t) return r;
    return -1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    while(q--) {
        int k;
        cin >> k;
        int start = lower(arr, k);
        int end = upper(arr, k);
        cout << start << " " << end << "\n";
    }
    return 0;
}