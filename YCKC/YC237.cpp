#include <bits/stdc++.h>
using namespace std;
int judge(int a, int b) {
    if(a == b) return 0;
    if((a == 0 && b == 2) || (a == 2 && b == 5) || (a == 5 && b == 0)) return 1;
    return -1;
}
int main() {
    int N, NA, NB;
    cin >> N >> NA >> NB;
    vector<int> A(NA), B(NB);
    for(int i = 0; i < NA; ++i) cin >> A[i];
    for(int i = 0; i < NB; ++i) cin >> B[i];

    int winA = 0, winB = 0;
    for(int i = 0; i < N; ++i) {
        int res = judge(A[i % NA], B[i % NB]);
        if(res == 1) winA++;
        else if(res == -1) winB++;
    }
    if(winA > winB) cout << "A\n";
    else if(winB > winA) cout << "B\n";
    else cout << "draw\n";
    return 0;
}