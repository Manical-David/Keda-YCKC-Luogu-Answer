#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int m;
    cin >> m;
    set<long long> woods;
    while (m--) {
        int op;
        long long length;
        cin >> op >> length;
        if (op == 1) {
            if (woods.count(length)) {
                cout << "Already Exist\n";
            } else {
                woods.insert(length);
            }
        } else {
            if (woods.empty()) {
                cout << "Empty\n";
            } else {
                auto it = woods.find(length);
                if (it != woods.end()) {
                    cout << *it << '\n';
                    woods.erase(it);
                } else {
                    it = woods.upper_bound(length);
                    long long selected;
                    if (it == woods.begin()) {
                        selected = *it;
                    } else if (it == woods.end()) {
                        --it;
                        selected = *it;
                    } else {
                        long long higher = *it;
                        --it;
                        long long lower = *it;
                        
                        if (length - lower <= higher - length) {
                            selected = lower;
                        } else {
                            selected = higher;
                        }
                    }
                    
                    cout << selected << '\n';
                    woods.erase(selected);
                }
            }
        }
    }

    return 0;
}