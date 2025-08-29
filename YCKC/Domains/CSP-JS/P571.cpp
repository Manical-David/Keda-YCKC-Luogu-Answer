#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<multiset<int>> boxes(N + 1);
    unordered_map<int, set<int>> num_to_boxes;
    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, j;
            cin >> i >> j;
            boxes[j].insert(i);
            if (num_to_boxes[i].find(j) == num_to_boxes[i].end()) {
                num_to_boxes[i].insert(j);
            }
        } else if (op == 2) {
            int i;
            cin >> i;
            bool st1 = true;
            for (int num : boxes[i]) {
                if (!st1) {
                    cout << ' ';
                }
                st1 = false;
                cout << num;
            }
            cout << '\n';
        } else if (op == 3) {
            int i;
            cin >> i;
            bool st1 = true;
            for (int box : num_to_boxes[i]) {
                if (!st1) {
                    cout << ' ';
                }
                st1 = false;
                cout << box;
            }
            cout << '\n';
        }
    }
    return 0;
}