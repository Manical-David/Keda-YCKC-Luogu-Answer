#include<bits/stdc++.h>
using namespace std;
char S[500010];
signed main() {
	int n;
    bool flag = false;
	deque <int> dq;
	// cin >> n;
    scanf("%d", &n);
	for(int i = 1; i <= n; i++) dq.push_back(i);
	scanf("%s", &S[1]);
	for(int i = 1; S[i] != '\0'; i++) {
		if(S[i] == 'f') flag =! flag;
		if(S[i] == 'r') {
			if(flag)
				dq.push_back(dq.front()), dq.pop_front();
			else dq.push_front(dq.back()), dq.pop_back();
		}
	}
	if(flag) {
        while(!dq.empty()) {
		    printf("%d\n", dq.back());
		    dq.pop_back();
	    }
    }
	else {
        while(!dq.empty()) {
		    printf("%d\n", dq.front());
		    dq.pop_front();
	    }
    }
	return 0;
}