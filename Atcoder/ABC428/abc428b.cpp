#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    unordered_map<string, int> cnts;
    for (int i = 0; i <= N - K; ++i) {
        string subs = S.substr(i, K);
        cnts[subs]++;
    }
    int maxn = 0;
    for (const auto& pair : cnts) {
        if (pair.second > maxn) {
            maxn = pair.second;
        }
    }
    vector<string> maxsubs;
    for (const auto& pair : cnts) {
        if (pair.second == maxn) {
            maxsubs.push_back(pair.first);
        }
    }
    sort(maxsubs.begin(), maxsubs.end());
    cout << maxn << endl;
    for (size_t i = 0; i < maxsubs.size(); ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << maxsubs[i];
    }
    cout << endl;
    return 0;
}
