#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    if(n > 0) cout << "positive\n";
    else if(n == 0) cout << "zero\n";
    else if(n < 0) cout << "negative\n";
    return 0;
}