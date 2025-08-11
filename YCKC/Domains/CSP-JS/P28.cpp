#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, k, a[N];
bool check(int len) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cnt += a[i] / len;
    }
    return cnt >= k;
}
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int l = 1, r = 100000000;
    while(l < r) {
        int mid = l + r + 1>> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    if(check(l)) cout << l;
    else cout << 0;
    return 0;
}