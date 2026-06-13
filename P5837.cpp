#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
class DSU { // Leetcode后遗症
    unordered_map<int, int> fu;
    unordered_map<int, int> rank;
public:
    int find(int x) {
        if (!fu.count(x)) {
            fu[x] = x;
            rank[x] = 0;
            return x;
        }
        if (fu[x] != x) {
            fu[x] = find(fu[x]);
        }
        return fu[x];
    }
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) {
            fu[px] = py;
        } else if (rank[px] > rank[py]) {
            fu[py] = px;
        } else {
            fu[py] = px;
            rank[px]++;
        }
    }
    bool cc(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    unordered_map<int, vector<int> > pos;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    unordered_map<int, int> mind;
    auto calculateMinDist = [](const vector<int>& positions) -> int {
        if (positions.size() < 2) return INF;
        int min_val = INF;
        for (size_t i = 1; i < positions.size(); i++) {
            min_val = min(min_val, positions[i] - positions[i-1]);
        }
        return min_val;
    };
    for (auto& [val, positions] : pos) {
        sort(positions.begin(), positions.end());
        mind[val] = calculateMinDist(positions);
    }
    int flbm = INF;
    for (auto& [val, dist] : mind) {
        if (dist < flbm) {
            flbm = dist;
        }
    }
    DSU dsu; // 听你的，T了怪你
    vector<int> res;
    for (int op = 0; op < m; op++) {
        int x, y;
        cin >> x >> y;
        if (!pos.count(x) || pos[x].empty()) {
            res.push_back(flbm);
            continue;
        }
        if (x == y) {
            res.push_back(flbm);
            continue;
        }
        int rx = dsu.find(x);
        int ry = dsu.find(y);
        int repX = rx == x ? x : (dsu.find(rx) == rx ? rx : dsu.find(rx));
        int repY = ry == y ? y : (dsu.find(ry) == ry ? ry : dsu.find(ry));
        if (repX != repY) {
            dsu.unite(repX, repY);
            if (!pos.count(repY)) {
                pos[repY] = pos[repX];
            } else {
                vector<int> merged;
                merge(pos[repX].begin(), pos[repX].end(),
                      pos[repY].begin(), pos[repY].end(),
                      back_inserter(merged));
                pos[repY] = merged;
            }
            pos.erase(repX);
            mind[repY] = calculateMinDist(pos[repY]);
            mind.erase(repX);
            flbm = INF;
            for (auto& [val, dist] : mind) {
                if (dist < flbm) {
                    flbm = dist;
                }
            }
        }
        
        res.push_back(flbm);
    }
    for (int res : res) {
        cout << res << "\n";
    }
    
    return 0;
}