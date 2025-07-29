#include <bits/stdc++.h>
using namespace std;
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> img1(m, vector<int>(n));
    vector<vector<int>> img2(m, vector<int>(n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> img1[i][j];
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> img2[i][j];
        }
    }
    int cnt = 0;
    int total = m * n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(img1[i][j] == img2[i][j])
                cnt++;
        }
    }
    double ans = (double)cnt / total * 100.0;
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}