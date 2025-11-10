#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    cin >> N;
    if (N <= 0) {
        cerr << "Error: invalid cin" << '\n';
        return 1;
    }
    vector<string> strs;
    for (int i = 0; i < N; i++) {
        string it;
        cin >> it;
        strs.push_back(it);
    }
    stack<string> pre_st;
    stack<string> in_st;
    for (int i = 0; i < N; i++) {
        string it = strs[i];
        if (it == "+" || it == "-" || it == "*" || it == "/" || it == "%") {
            if (pre_st.size() < 2) {
                cerr << "Error: undefined '" << it << "'" << '\n'; // Debug
                return 1;
            }
            string rp = pre_st.top();
            pre_st.pop();
            string lp = pre_st.top();
            pre_st.pop();
            string newp = it + " " + lp + " " + rp;
            pre_st.push(newp);
            string rin = in_st.top();
            in_st.pop();
            string lin = in_st.top();
            in_st.pop();
            string new_infix = lin + " " + it + " " + rin;
            in_st.push(new_infix);
        } 
        else {
            pre_st.push(it);
            in_st.push(it);
        }
    }
    if (pre_st.size() != 1 || in_st.size() != 1) {
        cerr << "Error: it is impossible to get the answer" << '\n'; // Debug
        return 1;
    }
    cout << pre_st.top() << '\n';
    cout << in_st.top() << '\n';
    return 0;
}
