#include <bits/stdc++.h>
using namespace std;
long long a[100000];
int main() {
	freopen("sort.in", "r", stdin); // ⚠️注意！5，6行必不可少！否则会0RE！
	freopen("sort.out", "w", stdout);
	long long n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}