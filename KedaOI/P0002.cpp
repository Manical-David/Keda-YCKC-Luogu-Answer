#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 20;
int n, m, vol, p[N], v[N], w[N], f[N];
int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
int main() {
    cin >> n >> m >> vol;
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    while(m--) {
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if(pa != pb) {
            v[pb] += v[pa];
            w[pb] += w[pa];
            p[pa] = pb;
        }
    }
    for(int i = 1; i <= n; i++) {
    	for(int j = vol; j >= v[i]; j--){
            int pi = find(i);
            if(i == pi) f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
	}
    cout << f[vol];
    return 0;
}