#include <iostream>
using namespace std;

const int N = 10005;
int a[N], b[N], g[N], k[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }
    int x, y;
    cin >> x >> y;
    int ans = -1;
    for(int i = n; i >= 1; i--) {
        if(x >= a[i] && x <= a[i] + g[i] && y >= b[i] && y <= b[i] + k[i]) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}