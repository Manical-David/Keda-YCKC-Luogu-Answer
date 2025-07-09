#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int k = 5;
ll pow(ll a, ll b, ll p) {
	ll res = 1 % p;
	for (; b; b >>= 1) {
		if (b & 1) res = res * a % p;
	a = a * a % p;
	}
	return res;
}
bool isprime(ll n) {
	if (n < 3 || !(n & 1)) return n == 2;
	ll u = n - 1, t = 0;
	while (!(u & 1)) u >>= 1, t++;
	for (int i = 0; i < k; i++) {
		ll a = rand() % (n - 2) + 2, v = pow(a, u, n), s;
		for (s = 0; s < t; s++) {
			if (v == n - 1 || v == 1) break;
			v = (ll)v * v % n;
		}
		if (s == t) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	ll n;
	while (cin >> n) cout << (isprime(n) ? "Y\n" : "N\n");
}