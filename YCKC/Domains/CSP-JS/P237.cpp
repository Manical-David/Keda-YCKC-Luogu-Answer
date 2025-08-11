#include <bits/stdc++.h>
using namespace std;
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << from << "->" << n << "->" << to << endl;
        return;
    }
    hanoi(n - 1, from, aux, to);
    cout << from << "->" << n << "->" << to << endl;
    hanoi(n - 1, aux, to, from);
}
int main() {
    int n;
    char from, to, aux;
    cin >> n >> from >> to >> aux;
    hanoi(n, from, to, aux);
    return 0;
}