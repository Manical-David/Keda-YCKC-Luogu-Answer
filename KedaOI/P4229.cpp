#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, a[N];
long long sum = 0;
stack <int> p;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] 
	}
	for (int i = 1; i <= n; i++) {
		while (!p.empty() && a[i] > a[p.top()]) {
			int t = p.top();
			p.pop();
			if (!p.empty()) {
				int l = p.top();
				int w = i - 1 - l;
				int h = min(a[i], a[l]) - a[t];
				sum += 1ll * h * w;
			}
		}
		p.push(i);
	}
	cout << sum << '\n';
}