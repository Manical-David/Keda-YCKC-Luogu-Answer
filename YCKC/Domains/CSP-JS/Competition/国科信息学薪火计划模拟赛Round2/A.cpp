#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string str;
    getline(cin, str);
    stack <char> st;
    for(char c : str) {
        if(!st.empty()) {
            char tp = st.top();
            if((tp == 'A' && c == 'P') || (tp = 'P' && c == 'P')) {
                st.pop();
                continue;
            }
        }
        st.push(c);
    }
    cout << st.size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}