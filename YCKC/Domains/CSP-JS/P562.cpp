#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mul(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res + a) % mod;
        }
        a = (a * 2) % mod;
        b /= 2;
    }
    return res % mod;
}
ll pow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) {
            res = mul(res, a, mod);
        }
        a = mul(a, a, mod);
        b /= 2;
    }
    return res % mod;
}
bool milr(ll n, ll a) {
    if (n == 2 || n == a) {
        return true;
    }
    if (n % 2 == 0 || n < 2) {
        return false;
    }
    ll d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }
    ll x = pow(a, d, n);
    if (x == 1 || x == n - 1) {
        return true;
    }
    while (d != n - 1) {
        x = mul(x, x, n);
        d *= 2;
        if (x == 1) {
            return false;
        }
        if (x == n - 1) {
            return true;
        }
    }
    return false;
}
bool isprime(ll n) {
    if (n < 2) {
        return false;
    }
    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}) {
        if (n == a) {
            return true;
        }
        if (!milr(n, a)) {
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        cout << (isprime(N) ? "yes" : "no") << '\n';
    }
    return 0;
}