#include <bits/stdc++.h>
using namespace std;

struct Piece { long long h, w; int idx; };
struct Space {
    long long x, y, h, w;
    bool operator<(const Space& other) const {
        long long A = h * w;
        long long B = other.h * other.w;
        if (A != B) return A < B;        // larger area first
        if (h != other.h) return h < other.h;
        if (x != other.x) return x > other.x;
        return y > other.y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long H, W;
    int N;
    if (!(cin >> H >> W >> N)) return 0;

    vector<Piece> pieces(N);
    for (int i = 0; i < N; ++i) {
        cin >> pieces[i].h >> pieces[i].w;
        pieces[i].idx = i;
    }

    sort(pieces.begin(), pieces.end(), [](const Piece& a, const Piece& b) {
        long long A = a.h * a.w, B = b.h * b.w;
        if (A != B) return A > B;
        if (a.h != b.h) return a.h > b.h;
        return a.w > b.w;
    });

    priority_queue<Space> pq;
    pq.push({0, 0, H, W});
    vector<pair<long long,long long>> ans(N);

    for (auto &pc : pieces) {
        bool placed = false;
        vector<Space> stash;
        while (!pq.empty() && !placed) {
            Space cur = pq.top(); pq.pop();
            if (pc.h <= cur.h && pc.w <= cur.w) {
                ans[pc.idx] = {cur.x, cur.y};
                placed = true;
                if (pc.h < cur.h) pq.push({cur.x + pc.h, cur.y, cur.h - pc.h, cur.w});
                if (pc.w < cur.w) pq.push({cur.x, cur.y + pc.w, pc.h, cur.w - pc.w});
            } else {
                stash.push_back(cur);
            }
        }
        for (auto &s : stash) pq.push(s);
        if (!placed) return 1; // should not happen (input guaranteed valid)
    }

    for (int i = 0; i < N; ++i) cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    return 0;
}