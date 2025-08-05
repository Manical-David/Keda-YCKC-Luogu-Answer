#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    if(n > 0) cout << "positive";
    else if(n == 0) cout << "zero";
    else if(n < 0) cout << "negative";
    return 0;
}