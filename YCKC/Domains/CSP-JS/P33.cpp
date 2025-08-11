#include <bits/stdc++.h>
using namespace std;
int n;
long long r, nb, ns, nc, pb, ps, pc, b, s, c;
char ch[105];
bool check(long long x) {
	long long cnt = 0;
	if(x * b - nb > 0) cnt += (x * b - nb) * pb;
	if(x * s - ns > 0) cnt += (x * s - ns) * ps;
	if(x * c - nc > 0) cnt += (x * c - nc) * pc;
	return cnt <= r;
}
int main() {
	cin >> ch >> nb >> ns >> nc >> pb >> ps >> pc >> r;
	int len = strlen(ch);
	for(int i = 0; i < len; i++) {
		if(ch[i] == 'B') b++;
		else if(ch[i] == 'S') s++;
		else c++;
	}
	long long L = 0, R = r + 1000, mid;
	while(L < R) {
		mid = (L + R + 1) / 2;
		if(check(mid)) L = mid;
		else R = mid - 1;
	}
	cout << L;
	return 0;
}