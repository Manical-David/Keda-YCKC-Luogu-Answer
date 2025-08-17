#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    cin >> N;
    unordered_map<string, int> mp;
    for (int i = 0; i < N; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            string str;
            int score;
            cin >> str >> score;
            mp[str] = score;
            cout << "OK\n";
        } 
        else if (op == 2) {
            string str;
            cin >> str;
            auto it = mp.find(str);
            if (it != mp.end()) {
                cout << it->second << '\n';
            } else {
                cout << "Not found\n";
            }
        } 
        else if (op == 3) {
            string str;
            cin >> str;
            auto it = mp.find(str);
            if (it != mp.end()) {
                mp.erase(it);
                cout << "Deleted successfully\n";
            } else {
                cout << "Not found\n";
            }
        } else if (op == 4) {
            cout << mp.size() << '\n';
        }
    }
    return 0;
}