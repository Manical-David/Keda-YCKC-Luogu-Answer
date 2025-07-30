#include <bits/stdc++.h>
using namespace std;
struct cow {
    int s, t, b;
    bool operator<(const cow& other) const {
        return s < other.s;
    }
};
int main() {
    int N;
    cin >> N;
    vector<cow> cows(N);
    for (int i = 0; i < N; ++i) {
        cin >> cows[i].s >> cows[i].t >> cows[i].b;
    }
    sort(cows.begin(), cows.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 双队自带排序vector+pair
    int tong = 0;
    int maxx = 0;
    for (int i = 0; i < N; ++i) {
        int now = cows[i].s;
        while (!pq.empty() && pq.top().first <= now) {
            tong -= pq.top().second;
            pq.pop();
        }
        tong += cows[i].b;
        pq.push({cows[i].t, cows[i].b});
        maxx = max(maxx, tong);
    }
    cout << maxx << endl;
    return 0;
}