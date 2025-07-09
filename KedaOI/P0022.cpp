#include <bits/stdc++.h>
using namespace std;
int main() {
    int i, S= 1, N;
    cin >> N;
    for (i = 1; i <= N; i++)
        S = S * i;
    cout << S;
    return 0;
}