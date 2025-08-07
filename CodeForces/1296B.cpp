#include<bits/stdc++.h>
using namespace std;
void solve() {
    int a;
    cin >> a;
    int s = 0, k = 0;
    while(a >= 10) {
        s = a - (a % 10);
        k += s;
        a -= s;
        a += s / 10;
    }
    cout << k + a << '\n';
}
int main(){
	int t;
    cin >> t;
	while(t--) {
	    solve();
	}
	return 0;
}