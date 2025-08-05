// 即编一个程序，如果R低于1200，输出ABC；如果R高于或等于1200且低于2800，输出ARC；如果R高于或等于2800，输出AGC。
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int r;
    cin >> r;
    if(r < 1200) cout << "ABC";
    else if(r >= 1200 && r < 2800) cout << "ARC";
    else if(r >= 2800) cout << "AGC";
    return 0;
}