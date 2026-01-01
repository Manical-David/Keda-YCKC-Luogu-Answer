#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    set <int> st;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        st.insert(num);
    }
    cout << st.size();
    return 0;
}