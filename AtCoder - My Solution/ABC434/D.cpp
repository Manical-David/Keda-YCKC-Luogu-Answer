#include <bits/stdc++.h>
using namespace std;
int N = 2010;
struct claud {
    int a, b, c, d;
};
void compare(int &a, int &b, int &c, int &d) {
    a = min(a, c);
    b = min(b, d);
    c = max(a, c);
    d = min(b, d);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    vector <vector <int> > map(N, vector <int> (N, 0));
    int n;
    cin >> n;
    vector <claud> clouds(n);
    int maxnx = INT_MIN;
    int maxny = maxnx;
    int minnx = INT_MAX;
    int minny = minnx;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        compare(a, b, c, d);
        clouds[i] = {a, b, c, d};
        for (int j = a - 1; j < c - 1; j++) {
            for (int k = b - 1; k < d - 1; k++) {
                map[j][k]++;
            } 
        }
    }
    for (int j = minny; j < maxny; j++) {
        for (int k = minnx; k < maxnx; k++) {
            cout << map[j][k] << ' ';
        }
        cout << endl;
    }
    puts("");
    for (int i = 0; i < n; i++) {
        int a = clouds[i].a, b = clouds[i].b, c = clouds[i].c, d = clouds[i].d;
        int cnt = 0;
        for (int j = a - 1; j < c - 1; j++) {
            for (int k = b - 1; k < d - 1; k++) {
                map[j][k]--;
                if (map[j][k] >= 1) cnt++;
            } 
        }
        // cout << 4000000 - cnt << '\n';
        // for (int j = 0; j < 2000; j++) {
        //     for (int k = 0; k < 2000; k++) {
        //         cout << map[j][k] << ' ';
        //     }
        //     cout << endl;
        // }
        // puts("");
    }
    return 0;
}