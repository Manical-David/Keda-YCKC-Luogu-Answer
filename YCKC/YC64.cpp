#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    if(n <= 59) cout << 'E';
    else if(n >= 60 && n <= 69) cout << "D";
    else if(n >= 70 && n <= 79) cout << "C";
    else if(n >= 80 && n <= 89) cout << "B";
    else if(n >= 90) cout << "A";
    return 0;
}