#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    stack <int> st;
    int maxx = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') {
            st.push(i);
        } 
        else if (s[i] == 'B') {
            if (!st.empty()) {
                int a_pos = st.top();
                st.pop();
                int tong = i - a_pos;
                if (tong > maxx) {
                    maxx = tong;
                }
            }
        }
    }
    cout << maxx << '\n';
    return 0;
}
