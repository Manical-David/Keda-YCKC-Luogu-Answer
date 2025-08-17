#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100010;
struct Node {
    int val;
    int prev, next;
    Node() : val(0), prev(-1), next(-1) {}
    Node(int v) : val(v), prev(-1), next(-1) {}
};
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    vector<Node> nodes(N);
    int head = -1;
    int tail = -1;
    int idx = 0;
    vector<int> ins;
    int m;
    cin >> m;
    while (m--) {
        string op;
        cin >> op;
        if (op == "L") {
            int x;
            cin >> x;
            nodes[idx] = Node(x);
            if (head == -1) {
                head = tail = idx;
            } else {
                nodes[idx].next = head;
                nodes[head].prev = idx;
                head = idx;
            }
            ins.push_back(idx);
            idx++;
        } else if (op == "R") {
            int x;
            cin >> x;
            nodes[idx] = Node(x);
            if (tail == -1) {
                head = tail = idx;
            } else {
                nodes[idx].prev = tail;
                nodes[tail].next = idx;
                tail = idx;
            }
            ins.push_back(idx);
            idx++;
        } 
        else if (op == "D") {
            int k;
            cin >> k;
            int cur = ins[k - 1];
            int p = nodes[cur].prev;
            int n = nodes[cur].next;
            if (p != -1) {
                nodes[p].next = n;
            } else {
                head = n;
            }
            if (n != -1) {
                nodes[n].prev = p;
            } else {
                tail = p;
            }
        } 
        else if (op == "IL") {
            int k, x;
            cin >> k >> x;
            int cur = ins[k - 1];
            int p = nodes[cur].prev;
            nodes[idx] = Node(x);
            nodes[idx].prev = p;
            nodes[idx].next = cur;
            nodes[cur].prev = idx;
            if (p != -1) {
                nodes[p].next = idx;
            } else {
                head = idx;
            }
            
            ins.push_back(idx);
            idx++;
        } else if (op == "IR") {
            int k, x;
            cin >> k >> x;
            int cur = ins[k - 1];
            int n = nodes[cur].next;
            nodes[idx] = Node(x);
            nodes[idx].prev = cur;
            nodes[idx].next = n;
            nodes[cur].next = idx;
            if (n != -1) {
                nodes[n].prev = idx;
            } else {
                tail = idx;
            }
            ins.push_back(idx);
            idx++;
        }
    }
    int cur = head;
    while (cur != -1) {
        cout << nodes[cur].val << " ";
        cur = nodes[cur].next;
    }
    return 0;
}
    