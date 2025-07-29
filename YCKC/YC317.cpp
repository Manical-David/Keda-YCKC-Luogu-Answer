#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int N, M;
    cin >> N >> M;
    vector<vector<int>> maz(N, vector<int>(M));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> maz[i][j];
        }
    }
    int Q;
    cin >> Q;
    while(Q--){
        int x, y;
        cin >> x >> y;
        swap(maz[x-1], maz[y-1]);
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << maz[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}