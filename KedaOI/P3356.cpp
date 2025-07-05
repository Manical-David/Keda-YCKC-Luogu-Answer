#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int e[N], ne[N], head, idx, pos[N];
void init() {
    head = -1;
    idx = 0;
}
void ins(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    pos[++idx] = head; 
}
void remove(int k) {
    if (k == 0) {
        head = ne[head];
    } else {
        int node = pos[k];
        ne[node] = ne[ne[node]];
    }
}
void insert(int k, int x) {
    int node = pos[k]; 
    e[idx] = x;
    ne[idx] = ne[node];
    ne[node] = idx;
    pos[++idx] = idx;
}

int main() {
    init();
    int m;
    cin >> m;
    int k = 0;
    while (m--) {
        char op;
        cin >> op;
        if (op == 'H') {
            int x;
            cin >> x;
            ins(x);
            k++;
        } else if (op == 'D') {
            int kth;
            cin >> kth;
            remove(kth);
            if (kth == 0) k--;
        } else if (op == 'I') {
            int kth, x;
            cin >> kth >> x;
            insert(kth, x);
            k++;
        }
    }
    for (int i = head; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }
    return 0;
}