#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, z, Q;
    cin >> x >> y >> z >> Q;
    int tong = 0;
    tong = (x * 2) + (y * 5) + (z * 3);
    if(tong > Q) cout << "No\n";
    else cout << "Yes\n";
    cout << abs(tong - Q);
    return 0;
}
