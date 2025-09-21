#include <bits/stdc++.h>
using namespace std;
bool checker(int a, int b, int c) {
    return (c / b) < a;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    srand(time(0));
    int n, x, y;
    bool flag = false;
    do {
        n = rand() % INT_MAX;
        x = rand() % INT_MAX;
        y = rand() % INT_MAX;
        flag = checker(n, x, y);
    } while(!flag);
    printf("%d %d %d\n", n, x, y);
    return 0;
}