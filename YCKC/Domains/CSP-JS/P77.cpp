#include <bits/stdc++.h>
using namespace std;
bool tassk(const vector<int>& pushe, const vector<int>& pope) {
    stack<int> st;
    int i = 0;
    for (int num : pushe) {
        st.push(num);
        while (!st.empty() && st.top() == pope[i]) {
            st.pop();
            i++;
        }
    }
    return st.empty();
}
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> pushe(n);
        vector<int> pope(n);
        for (int i = 0; i < n; i++) {
            cin >> pushe[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> pope[i];
        }
        if (tassk(pushe, pope)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
