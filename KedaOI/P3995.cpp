#include <bits/stdc++.h>
using namespace std;
int main() {
    set<pair<string, string> > s;
    int n;
    cin >> n;
    while(n--) {
        string n, o;
        cin >> n >> o;
        s.insert({n, o});
    }
    cout << s.size() << endl;
    return 0;
}
// asdjnfalksd