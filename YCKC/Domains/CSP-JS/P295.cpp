#include <bits/stdc++.h>
using namespace std;
struct node {
    int val;
    int nxt;
    node() : val(0), nxt(-1) {}
    node(int v) : val(v), nxt(-1) {}
};
int main() {
    const int MAX_SIZE = 100010;
    vector<node> nodes(MAX_SIZE);
    int head = -1;
    int idx = 0;
    vector<int> ord;
    int M;
    cin >> M;
    while (M--) {
        char op;
        cin >> op;
        if (op == 'H') {
            int x;
            cin >> x;
            nodes[idx] = node(x);
            nodes[idx].nxt = head;
            head = idx;
            ord.push_back(idx);
            idx++;
        } else if (op == 'D') {
            int k;
            cin >> k;
            if (k == 0) {
                if (head != -1) {
                    head = nodes[head].nxt;
                }
            } else {
                int preidx = ord[k - 1];
                if (nodes[preidx].nxt != -1) {
                    int delIdx = nodes[preidx].nxt;
                    nodes[preidx].nxt = nodes[delIdx].nxt;
                }
            }
        } else if (op == 'I') {
            int k, x;
            cin >> k >> x;
            int preidx = ord[k - 1];
            nodes[idx] = node(x);
            nodes[idx].nxt = nodes[preidx].nxt;
            nodes[preidx].nxt = idx;
            ord.push_back(idx);
            idx++;
        }
    }
    int cur = head;
    while (cur != -1) {
        cout << nodes[cur].val << " ";
        cur = nodes[cur].nxt;
    }
    cout << endl;
    
    return 0;
}
