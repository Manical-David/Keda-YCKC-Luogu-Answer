#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n;
    cin >> n;
    string str = "";
    for(int i = 0; i < n; i++) {
        str += "Accepted,";
    }
    str.pop_back(); // 去掉最后一个逗号
    cout << str << endl;
    return 0;
}