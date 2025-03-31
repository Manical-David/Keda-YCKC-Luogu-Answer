#include <bits/stdc++.h>
using namespace std;
constexpr int N = INT_MAX - 1;
int tong[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num > 0) {
            tong[num] = 1;
        }
    }
    int min = 0;
    for(int i = 0; i < N && tong[i] == 0; i++) {
        min = i;
    }
    min++;
    for(int i = min; i < N; i++) {
        if(tong)
    }
    return 0;
}