#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
	cin >> n;
	if(n >= 90){
		cout << "Great";
	}else if(n >= 70){
		cout << "Good";
	}else if(n>=60){
		cout << "Average";
	}else{
		cout << "Poor";
	} 
	return 0;
}