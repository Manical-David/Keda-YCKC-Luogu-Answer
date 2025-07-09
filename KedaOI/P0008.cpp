#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin >> a;
    int bai, shi, ge;
    bai = a / 100;
    shi = a % 100 / 10;
    ge = a % 10;
    if(bai * bai * bai + shi * shi * shi + ge * ge * ge == a) {
        cout << "TRUE";
    } else {
        cout << "FALSE";
    }
    return 0;
}