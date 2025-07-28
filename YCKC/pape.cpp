#include <bits/stdc++.h>
using namespace std;
string in, post;
void build(int inL, int inR, int postL, int postR) {
    if(inL > inR || postL > postR) return;
    char root = post[postR];
    cout << root;
    int rootIndex = in.find(root, inL);
    int leftSize = rootIndex - inL;
    build(inL, rootIndex - 1, postL, postL + leftSize - 1);
    build(rootIndex + 1, inR, postL + leftSize, postR - 1);
}
int main() {
    cin >> in >> post;
    int n = in.size();
    build(0, n - 1, 0, n - 1);
    cout << endl;
    return 0;
}
}