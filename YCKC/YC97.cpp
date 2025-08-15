#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    int x = a[0], y = a[1], z = a[2];
    if (x + y <= z) {
        cout << "Not triangle" << '\n';
        return 0;
    }
    bool is_right = false;
    bool is_acute = false;
    bool is_obtuse = false;
    int sum_sq = x * x + y * y;
    int z_sq = z * z;
    if (sum_sq == z_sq) {
        is_right = true;
    } else if (sum_sq > z_sq) {
        is_acute = true;
    } else {
        is_obtuse = true;
    }
    if (is_right) {
        cout << "Right triangle" << '\n';
    }
    if (is_acute) {
        cout << "Acute triangle" << '\n';
    }
    if (is_obtuse) {
        cout << "Obtuse triangle" << '\n';
    }
    if (x == y || y == z || x == z) {
        cout << "Isosceles triangle" << '\n';
    }
    if (x == y && y == z) {
        cout << "Equilateral triangle" << '\n';
    }
    return 0;
}