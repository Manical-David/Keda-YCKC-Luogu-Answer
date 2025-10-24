#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int Q;
    if (!(cin >> Q)) return 0;
    vector<pair<int,int>> st;
    st.reserve(Q);
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            char c;
            cin >> c;
            int delt = (c == '(') ? 1 : -1;
            int ppre = st.empty() ? 0 : st.back().first;
            int minpre = st.empty() ? 0 : st.back().second;
            int npre = ppre + delt;
            int nmin = st.empty() ? min(0, npre) : min(minpre, npre);
            st.emplace_back(npre, nmin);
        } 
        else {
            st.pop_back();
        }
        int anspre = st.empty() ? 0 : st.back().first;
        int minn = st.empty() ? 0 : st.back().second;
        if (anspre == 0 && minn >= 0) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}