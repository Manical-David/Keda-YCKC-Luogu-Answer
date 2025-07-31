#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n;
    scanf("%d", &n);
    string num = to_string(n);
    int sum = 0;
    for(const auto it : num) {
        sum += it - '0';
    }
    printf("%d\n%d\n%d", sum, sum * sum, sum * sum * sum);
    return 0;
}