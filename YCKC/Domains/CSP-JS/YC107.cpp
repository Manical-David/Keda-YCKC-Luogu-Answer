#include <bits/stdc++.h>
using namespace std;
bool diff(vector <int> nums) {
    set <int> st;
    for (int it : nums) {
        st.insert(it);
    }
    return st.size() == 2;
}
bool lian(vector <int> nums) {
    sort(nums.begin(), nums.end());
    int minn = *min_element(nums.begin(), nums.end()), maxn = *max_element(nums.begin(), nums.end());
    int iter = 0;
    for (int i = minn; i <= maxn; i++) {
        if (nums[iter] != i) return false;
        iter++;
    }
    return true;
}
int levelchecker(int a, int b, int c) {
    if (a == 2 && b == 3 && c == 5) {
        return 5;
    }
    else if (a == b && b == c) {
        return 4;
    }
    else if (lian({a, b, c})) {
        return 3;
    }
    else if (diff({a, b, c})) {
        return 2;
    }
    else return 1;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int x, y, z;
    int a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    int levela = levelchecker(x, y, z), levelb = levelchecker(a, b, c);
    if (levela == levelb) {
        int suma = x + y + z, sumb = a + b + c;
        if (suma > sumb) {
            cout << "A";
            return 0;
        }
        else if (sumb > suma) {
            cout << "B";
            return 0;
        }
        else if (sumb == suma) {
            cout << "B";
            return 0;
        }
    }
    else if (levela > levelb) {
        cout << "A";
    }
    else if (levelb > levela) {
        cout << "B";
    }
    return 0;
}