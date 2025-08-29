#include<bits/stdc++.h>
using namespace std;
bool checker(int n) {
	if(n % 400 == 0){
		return true;
	}
    else if(n % 4 == 0 && n % 100 != 0){
		return true;
	}
    else{
		return false;
	}
	return 0;
}
int main() {
    vector <int> days = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year;
    cin >> year;
    if(checker(year)) {
        days[1] = 29;
    }
    else if(!checker(year)) days[1] = 28;
    int month;
    cin >> month;
    cout << days[month - 1];
    return 0;
}