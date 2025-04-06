#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        st.insert(t);
    }
    for (int i = 1; i <= n + 5; i++) {
        if (!st.count(i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}