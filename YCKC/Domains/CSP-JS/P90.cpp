#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int M, N;
    cin >> M >> N;
    vector<int> passage(N);
    for (int i = 0; i < N; i++) {
        cin >> passage[i];
    }
    deque<int> memory;
    int ans = 0;
    for (int word : passage) {
        auto it = find(memory.begin(), memory.end(), word);
        if (it != memory.end()) {
            memory.erase(it);
            memory.push_back(word);
        } else {
            ans++;
            if (memory.size() == M) {
                memory.pop_front();
            }
            memory.push_back(word);
        }
    }
    cout << ans << endl;
    return 0;
}