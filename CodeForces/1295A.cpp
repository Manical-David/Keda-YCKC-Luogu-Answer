#include<bits/stdc++.h>
using namespace std;
int n,t;
int main()
{
    cin >> t;
	while(t--) {
		cin >> n;
		if(n & 1) {
			cout << 7;
			n-=3;
		}
		while(n) {
			cout << 1;
			n-=2;
		}
		cout << char(10);
	}
	return 0;
}