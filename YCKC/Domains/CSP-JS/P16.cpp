#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> A(n), B(m);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < m; i++) cin >> B[i];
    int i = 0, j = m - 1;
    while(i < n && j >= 0) {
        int sum = A[i] + B[j];
        if(sum == x) {
            cout << i << " " << j << endl;
            return 0;
        }
        if(sum > x) j--;
        else i++;
    }
    
    return 0;
}