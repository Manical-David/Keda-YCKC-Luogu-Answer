#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    system("taskkill -f -im masterhelper.exe");
    system("sc stop tdnetfilter");
    system("pause");
    return 0;
}