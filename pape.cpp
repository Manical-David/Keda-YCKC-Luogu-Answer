#include <bits/stdc++.h>
#include <windows.h>
#include <ctime>
using namespace std;
int main() {
    int ok = 0, n; cout << "请输入对拍组数："; cin >> n;
    int maxt; cout << "\n请输入限制时间（毫秒，不需单位）："; cin >> maxt;]
    PROCESS_MEMORY_COUNTERS pmc;
    puts("");
    for (int i = 1; i <= n; ++i) {
        system("data.exe > in.txt");
        system("std.exe < in.txt > std.txt");
        double begin = clock();
        system("baoli.exe < in.txt > baoli.txt");
        double end = clock();
        double t = (end - begin);
        if (system("fc std.txt baoli.txt")) {
            printf("测试点#%d Wrong Answer\n", i);
        }
        else if (t > maxt) {
            printf("测试点#%d Time Limited Exceeded 用时 %.0lfms\n", i, t);
        }
        else {
            printf("测试点#%d Accepted 用时%.0lfms\n", i, t);
            ok++; //AC数量+1
        }
    }
    puts("");
    double res = 100.0 * ok / n;
    printf("共 %d 组测试数据，AC数据 %d 组。 得分%.1lf。", n, ok, res);
}
// 暴力解法：baoli.cpp -> baoli.exe 输出到baoli.txt
// 你的程序：std.cpp -> std.exe 输出到std.txt
// 数据生成：data.cpp -> data.exe 直接freopen in.txt w，输出