
#include <bits/stdc++.h>

using namespace std;

constexpr int N = 10;

int n;
vector<int> path;

// u代表当前选到了第几个元素
void dfs(int u) {
    // 搜索树的终止条件
    if (u == n + 1) {
        // 说明我们已经选完n个元素了
        for (const auto &it : path) {
            printf("%d ", it);
        }
        printf("\n");
        return;
    }
    // 搜索树的分裂条件
    // 1. 选择当前元素
    path.push_back(u);
    dfs(u + 1);
    // 2. 不选择当前元素
    // 得把之前更新的信息回退掉
    path.pop_back();
    dfs(u + 1);
}

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}