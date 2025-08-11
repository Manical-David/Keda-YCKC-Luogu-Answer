#include <bits/stdc++.h>
using namespace std;
vector<int> a;
void dfs(int n, int start) {
    if (n == 0) { 
        if (a.size() > 1) {
            for (int i = 0; i < a.size(); i++) {
                if (i > 0) cout << "+";
                cout << a[i];
            }
            cout << endl;
        }
        return;
    }
    for (int i = start; i <= n; i++) { 
        a.push_back(i); 
        dfs(n - i, i); 
        a.pop_back(); 
    }
}
int main() {
    int n;
    cin >> n;
    dfs(n, 1); 
    return 0;
}
