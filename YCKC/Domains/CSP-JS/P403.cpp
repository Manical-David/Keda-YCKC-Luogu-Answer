#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int>> heap;
    for (auto &it : a) {
        int l = it.first, r = it.second;
        if (heap.empty() || l <= heap.top()) {
            heap.push(r);
        } 
        else {
            heap.pop();
            heap.push(r);
        }
    }
    cout << heap.size() << '\n';
    return 0;
}