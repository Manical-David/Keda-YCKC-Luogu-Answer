#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> img(n, vector<int>(m));
    vector<vector<int>> answ(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> img[i][j];
            answ[i][j] = img[i][j];
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            int sum = img[i][j] + img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i][j + 1];
            answ[i][j] = round((double)sum / 5.0);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << answ[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}