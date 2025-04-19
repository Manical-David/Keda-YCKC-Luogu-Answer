#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string s1, s2;
    cin >> s1 >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for(int i = 0; i < s2.size(); i++) {
        if(s1[i] != s2[i]) {
            cout << s2[i] << '\n';
            break;
        }
    }
    return 0;
}
