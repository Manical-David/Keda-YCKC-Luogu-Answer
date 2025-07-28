#include <bits/stdc++.h>
using namespace std;
const int MAX_SUM = 300000005; // 3e8+5
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int N, M, L, Q;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    cin >> M;
    vector<int> B(M);
    for(int i = 0; i < M; ++i) cin >> B[i];
    cin >> L;
    vector<int> C(L);
    for(int i = 0; i < L; ++i) cin >> C[i];
    cin >> Q;
    vector<int> X(Q);
    for(int i = 0; i < Q; ++i) cin >> X[i];
    // 预处理B+C所有可能的和
    unordered_set<int> bc_sum;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < L; ++j) {
            bc_sum.insert(B[i] + C[j]);
        }
    }
    for(int i = 0; i < Q; ++i) {
        bool fnd = false;
        for(int j = 0; j < N; ++j) {
            int need = X[i] - A[j];
            if(bc_sum.count(need)) {
                fnd = true;
                break;
            }
        }
        cout << (fnd ? "Yes" : "No") << '\n';
    }
    return 0;
}