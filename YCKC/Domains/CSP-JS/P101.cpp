#include <bits/stdc++.h>
using namespace std;
string solve(string num, int k) {
    vector<char> st;
    for (char it : num) {
        while (!st.empty() && k > 0 && st.back() > it) {
            st.pop_back();
            k--;
        }
        st.push_back(it);
    }
    while (k > 0 && !st.empty()) {
        st.pop_back();
        k--;
    }
    string ans;
    bool ze = true;
    for (char it : st) {
        if (ze && it == '0') {
            continue;
        }
        ze = false;
        ans += it;
    }
    return ans.empty() ? "0" : ans;
}
int main() {
    string n;
    int k;
    cin >> n >> k;
    cout << solve(n, k) << '\n';
    return 0;
}