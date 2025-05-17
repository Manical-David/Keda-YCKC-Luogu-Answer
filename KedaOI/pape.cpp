#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m;
    cin >> m;
    
    vector<int> reachable(1001, false); // 最大值为1000
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        reachable[a] = true;
    }
    
    int n;
    cin >> n;
    
    // 向左扩展：找到最小的A，使得[A, n]中不包含可达元素
    int A = n;
    while (A > 1 && !reachable[A - 1]) {
        --A;
    }
    
    // 向右扩展：找到最大的B，使得[n, B]中不包含可达元素
    int B = n;
    while (B < 1000 && !reachable[B + 1]) {
        ++B;
    }
    
    int count = 0;
    for (int i = A; i <= n; ++i) {
        for (int j = n; j <= B; ++j) {
            if (i < j) {
                bool valid = true;
                for (int k = i; k <= j; ++k) {
                    if (reachable[k]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) count++;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}
