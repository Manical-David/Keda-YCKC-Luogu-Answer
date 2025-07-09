#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max = a[0], min = a[0];
    for(int i = 0; i < n; i++) {
        if(a[i] < min) min = a[i];
        else if(a[i] > max) max = a[i];
        else continue;
    }
    cout << min << ' ' << max;
    return 0;
}