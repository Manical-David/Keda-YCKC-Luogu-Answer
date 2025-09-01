#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    int num;
    vector <int> a;
    while(cin >> num) {
        a.push_back(num);
    }
    for(int i = a.size() - 1; i >= 0; i--) {
        cout << a[i] << '\n';
    }
    return 0;
}