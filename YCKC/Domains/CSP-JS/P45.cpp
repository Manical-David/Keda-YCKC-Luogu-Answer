#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> candies(n);
        for (int i = 0; i < n; i++) {
            cin >> candies[i];
        }
        int l = 0, r = n - 1;
        int alice = 0, bob = 0;
        int lasts = 0;
        int steps = 0;
        bool alice_flag = true;
        alice += candies[l++];
        lasts = candies[0];
        steps++;
        alice_flag = false;
        while (l <= r) {
            int curs = 0;
            bool check = false;
            if (alice_flag) {
                while (l <= r) {
                    curs += candies[l++];
                    if (curs > lasts) {
                        check = true;
                        break;
                    }
                }
                alice += curs;
            } else {
                while (l <= r) {
                    curs += candies[r--];
                    if (curs > lasts) {
                        check = true;
                        break;
                    }
                }
                bob += curs;
            }
            
            lasts = curs;
            steps++;
            alice_flag = !alice_flag;
            if (!check) {
                break;
            }
        }
        cout << steps << " " << alice << " " << bob << endl;
    }
    return 0;
}