#include <iostream>
#include <algorithm>
using namespace std;

// 判断骰子组合的等级和总和
pair<int, int> evaluate(int dice[]) {
    // 复制并排序，方便判断组合类型
    int temp[3] = {dice[0], dice[1], dice[2]};
    sort(temp, temp + 3);
    
    int sum = temp[0] + temp[1] + temp[2]; // 点数总和
    
    // 判断是否为三个一样的点数
    if (temp[0] == temp[1] && temp[1] == temp[2]) {
        return {4, sum};
    }
    
    // 判断是否为三个连续的点数
    if (temp[0] + 1 == temp[1] && temp[1] + 1 == temp[2]) {
        return {3, sum};
    }
    
    // 判断是否为两个一样的点数和另一个不一样的点数
    if (temp[0] == temp[1] || temp[1] == temp[2]) {
        return {2, sum};
    }
    
    // 其他情况
    return {1, sum};
}

// 检查是否为2 3 5（顺序无关）
bool is235(int dice[]) {
    int temp[3] = {dice[0], dice[1], dice[2]};
    sort(temp, temp + 3);
    return (temp[0] == 2 && temp[1] == 3 && temp[2] == 5);
}

int main() {
    int diceA[3], diceB[3];
    
    // 输入两组骰子点数
    cin >> diceA[0] >> diceA[1] >> diceA[2];
    cin >> diceB[0] >> diceB[1] >> diceB[2];
    
    // 获取等级和总和
    pair<int, int> resultA = evaluate(diceA);
    pair<int, int> resultB = evaluate(diceB);
    
    int levelA = resultA.first;  // A的组合等级
    int sumA = resultA.second;   // A的点数和
    int levelB = resultB.first;  // B的组合等级
    int sumB = resultB.second;   // B的点数和
    
    // 处理特殊规则：2 3 5 vs 三个一样的点数
    bool A_is_235 = is235(diceA);
    bool B_is_235 = is235(diceB);
    
    if (A_is_235 && levelB == 4) {
        // A是2 3 5，B是三个一样的点数，A获胜
        cout << "A" << endl;
        return 0;
    }
    
    if (B_is_235 && levelA == 4) {
        // B是2 3 5，A是三个一样的点数，B获胜
        cout << "B" << endl;
        return 0;
    }
    
    // 常规比较规则
    if (levelA > levelB) {
        // A的等级更高
        cout << "A" << endl;
    } else if (levelA < levelB) {
        // B的等级更高
        cout << "B" << endl;
    } else {
        // 等级相同，比较总和
        if (sumA > sumB) {
            cout << "A" << endl;
        } else {
            // sumA <= sumB，包括平局情况（输出B）
            cout << "B" << endl;
        }
    }
    
    return 0;
} // 看AI咋写的参考参考