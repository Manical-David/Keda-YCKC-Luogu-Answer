#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	if(n % 400 == 0){
		cout << "Y";
	}else if(n % 4 == 0 && n % 100 != 0){
		cout << "Y";
	}
    else {
		cout << "N";
	}
	return 0;
}