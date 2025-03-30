#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e4+ 7;
int a[N];
int main() {
    // ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n;
    scanf("%d", &n);
    multiset<int> st;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        st.insert(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (st.count(a[i]) > n / 2) {
            cout << a[i] << '\n';
            st.erase(a[i]);
        }
    }
    return 0;
}