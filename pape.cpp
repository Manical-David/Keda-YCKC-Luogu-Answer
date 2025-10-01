#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie();
	int 数量;
	cin >> 数量;
	vector <int> 初始(数量), 前缀和(数量);
	for(int i = 1; i <= 数量; i++) {
		cin >> 初始[i];
		前缀和[i] = 前缀和[i - 1] + 初始[i];
	}
	int t;
	cin >> t;
	while(t--) {
		int 头, 尾;
		cin >> 头 >> 尾;
		cout << 前缀和[尾] - 前缀和[头 - 1] << '\n';
	} 
	return 0;
}