#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main() {
    system("taskkill -f -im masterhelper.exe");
    system("sc stop tdnetfilter");
    system("pause");
    return 0;
}