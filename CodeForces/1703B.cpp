#include <bits/stdc++.h>
using namespace std;
int t, n, cnt = 0;
bool a[30];
string s;
int main(){
	scanf("%d", &t);
	while(t--) {
		memset(a, false, sizeof a);
		cnt = 0;
		scanf("%d", &n);
		cin>>s;
		for(int i = 0; i < s.length(); ++i){
			if(!a[s[i] - 'A']) ++cnt, a[s[i] - 'A'] = 1;
			++cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
